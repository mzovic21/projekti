using UnityEngine;

public class ChestGold : MonoBehaviour
{
    private Animator anim;
    [SerializeField] private GameObject player;
    [SerializeField] private GameObject text;

    [Header("Sounds")]
    [SerializeField] private AudioClip chestSound;

    private bool unlocked = false;
    public bool hammer = false;

    private void Awake()
    {
        anim = GetComponent<Animator>();
        text.SetActive(false);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.tag == "Player" && hammer)
        {
            SoundManager.instance.PlaySound(chestSound);
            anim.SetBool("IsOpened", true);
            player.GetComponent<PlayerMovement>().canDashJump = true;
            if (!unlocked)
            {
                text.SetActive(true);
                unlocked = true;
            }

        }
    }

    private void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.tag == "Player" && hammer)
        {
            anim.SetBool("IsOpened", false);
            text.SetActive(false);
        }
    }
}
