using System.Collections;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    [Header("Movement")]
    [SerializeField] private float speed;
    [SerializeField] private float fallSpeed;
    [SerializeField] private float coyoteTime;
    private float playerMovement;
    private Vector2 vecGravity;
    private float coyoteCounter;

    [Header("Jump")]
    [SerializeField] private bool canJump;
    [SerializeField] public bool canDoubleJump;
    [SerializeField] private float jumpHeight;
    [SerializeField] private float jumpDivider;
    private float timer;
    private bool doubleJump;

    [Header("Wall Jump")]
    [SerializeField] private bool canWallSlide;
    [SerializeField] public bool canWallJump;
    [SerializeField] private float wallJumpHeight;
    [SerializeField] private float wallSlidingSpeed;

    [Header("Dash")]
    [SerializeField] public bool canDash;
    [SerializeField] public bool canDashJump;
    [SerializeField] private float dashPower;
    [SerializeField] private float dashTime;
    [SerializeField] private float dashCooldown;
    private bool isDashing;
    private float playerGravity;

    [Header("Layers")]
    [SerializeField] private LayerMask groundLayer;
    [SerializeField] private LayerMask wallLayer;

    [Header("Sounds")]
    [SerializeField] private AudioClip jumpSound;
    [SerializeField] private AudioClip dashSound;

    private Rigidbody2D body;
    private Animator anim;
    private BoxCollider2D boxCollider;
    private TrailRenderer trail;

    private void Awake()
    {
        body = GetComponent<Rigidbody2D>();
        anim = GetComponent<Animator>();
        boxCollider = GetComponent<BoxCollider2D>();
        trail = GetComponent<TrailRenderer>();

        vecGravity = new Vector2(0, -Physics2D.gravity.y);
        playerGravity = body.gravityScale;
    }

    private void Update()
    {
        // player movement
        if (!isDashing)
            playerMovement = Input.GetAxisRaw("Horizontal") * speed * Time.deltaTime;

        flipPlayer();
        transform.Translate(playerMovement, 0f, 0f);

        // falling speed
        if (body.velocity.y < 0)
            body.velocity -= vecGravity * fallSpeed * Time.deltaTime;

        // animation parameters
        anim.SetBool("run", playerMovement != 0);
        anim.SetBool("grounded", isGrounded());
        anim.SetFloat("yVelocity", body.velocity.y);

        // jumping mechanics
        if (canJump)
        {
            // to prevent from early resseting counters
            timer += Time.deltaTime;

            if (timer > 0.05f)
            {
                // reset jump counter and coyote counter
                if (isGrounded() && (!onWall() || canWallJump))
                {
                    coyoteCounter = coyoteTime;
                    if (canDoubleJump) doubleJump = true;
                }

                timer = 0;
            }

            coyoteCounter -= Time.deltaTime;



            if (Input.GetKeyDown(KeyCode.Space))
            {
                timer = 0;
                Jump();
            }

            // adjustable jump height
            if (Input.GetKeyUp(KeyCode.Space) && body.velocity.y > 0)
                body.velocity = new Vector2(body.velocity.x, body.velocity.y / jumpDivider);
        }

        // wall sliding
        if (onWall() && canWallSlide)
        {
            body.velocity = new Vector2(body.velocity.x, Mathf.Clamp(body.velocity.y, -wallSlidingSpeed, float.MaxValue));
        }

        if (canDash)
        {
            if (Input.GetKeyDown(KeyCode.K))
            {
                SoundManager.instance.PlaySound(dashSound);
                isDashing = true;
                if (!canDashJump) canJump = false;
                StartCoroutine(Dash());
            }

        }
    }

    private void flipPlayer()
    {
        if (playerMovement > 0)
            transform.localScale = new Vector2(1.5f, 1.5f);
        else if (playerMovement < 0)
            transform.localScale = new Vector2(-1.5f, 1.5f);
    }

    private void Jump()
    {
        if (coyoteCounter <= 0 && !doubleJump && !onWall()) return;

        SoundManager.instance.PlaySound(jumpSound);

        if (onWall() && canWallJump)
        {
            WallJump();
        }

        else if (coyoteCounter > 0)
        {
            body.velocity = new Vector2(body.velocity.x, jumpHeight);
            coyoteCounter = 0;
        }

        else if (doubleJump)
        {
            body.velocity = new Vector2(body.velocity.x, jumpHeight);
            doubleJump = false;
        }
    }

    private void WallJump()
    {
        body.velocity = new Vector2(body.velocity.x, wallJumpHeight);
    }

    private IEnumerator Dash()
    {
        canDash = false;
        trail.emitting = true;
        body.gravityScale = 0;

        bool flag = false;

        if (transform.localScale.x > 0)
            body.velocity = Vector2.right * dashPower;
        else
            body.velocity = Vector2.left * dashPower;

        if (playerMovement == 0)
        {
            body.velocity *= speed;
            flag = true;
            canJump = false;
        }

        yield return new WaitForSeconds(dashTime);
        body.gravityScale = playerGravity;
        if (flag)
           body.velocity /= speed;

        isDashing = false;
        trail.emitting = false;
        canJump = true;
        yield return new WaitForSeconds(dashCooldown);
        canDash = true;
    }

    private bool isGrounded()
    {
        RaycastHit2D raycastHit = Physics2D.BoxCast(boxCollider.bounds.center, boxCollider.bounds.size, 0, Vector2.down, 0.1f, groundLayer);
        return raycastHit.collider != null;
    }

    private bool onWall()
    {
        RaycastHit2D raycastHit = Physics2D.BoxCast(boxCollider.bounds.center, boxCollider.bounds.size, 0, new Vector2(transform.localScale.x, 0), 0.1f, groundLayer);
        return raycastHit.collider != null;
    }
}
