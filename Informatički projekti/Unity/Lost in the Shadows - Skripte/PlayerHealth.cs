using UnityEngine;
using UnityEngine.Rendering.Universal;
using static UnityEngine.Rendering.DebugUI;

public class PlayerHealth : MonoBehaviour
{
    [Header("Health")]
    [SerializeField] private float startingHealth;
    [SerializeField] private float healthRegeneration;
    [SerializeField] private float healthWaste;
    public float currentHealth { get; private set; } // other scripts can access variable but can't change it

    [Header("Light")]
    [SerializeField] private float startingLightRange;

    [Header("Camera")]
    [SerializeField] private Camera mainCamera;
    [SerializeField] private float cameraSize;

    [Header("Sounds")]
    [SerializeField] private AudioClip deadSound;

    private bool dead;
    private bool isRegenerating;

    private Rigidbody2D body;
    private Animator anim;
    private Light2D spotLight;


    private void Awake()
    {
        currentHealth = startingHealth;

        body = GetComponent<Rigidbody2D>();
        anim = GetComponent<Animator>();
        spotLight = GetComponent<Light2D>();
    }

    public void Update()
    {
        if (body.IsSleeping()) body.WakeUp();
        if (isRegenerating || currentHealth <= 0) return;
        TakeDamage(healthWaste);
    }

    public void TakeDamage(float value)
    {
        if (value < 1) value *= Time.deltaTime;
        currentHealth = Mathf.Clamp(currentHealth - value, 0, startingHealth);
        spotLight.pointLightOuterRadius = Mathf.Clamp(spotLight.pointLightOuterRadius - value * 5, 0.5f, startingLightRange);
        mainCamera.orthographicSize = Mathf.Clamp(mainCamera.orthographicSize - value * 1.5f, 4f, cameraSize);

        if (currentHealth <= 0 && !dead)
        {
            SoundManager.instance.PlaySound(deadSound);
            GetComponent<PlayerMovement>().enabled = false;

            anim.SetBool("grounded", true);
            anim.SetTrigger("die");
            dead = true;
        }
    }

    public void AddHealth(float value)
    {
        if (value < 1) value *= Time.deltaTime;
        currentHealth = Mathf.Clamp(currentHealth + value, 0, startingHealth);
        spotLight.pointLightOuterRadius = Mathf.Clamp(spotLight.pointLightOuterRadius + value * 5, 0.5f, startingLightRange);
        mainCamera.orthographicSize = Mathf.Clamp(mainCamera.orthographicSize + value * 2, 3.5f, cameraSize);
    }

    public void Respawn()
    {
        dead = false;
        AddHealth(startingHealth);
        anim.ResetTrigger("die");
        anim.Play("Idle");

        GetComponent<PlayerMovement>().enabled = true;
    }

    private void OnTriggerStay2D(Collider2D collision)
    {
        if (collision.tag == "HealthArea" || collision.tag == "Checkpoint")
        {
            isRegenerating = true;
            if (currentHealth == startingHealth) return;
            AddHealth(healthRegeneration);
        }
    }

    private void OnTriggerExit2D(Collider2D collision)
    {
        isRegenerating = false;
    }

}
