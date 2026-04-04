using UnityEngine;

public class NPCDialogue : MonoBehaviour
{
    [SerializeField] private GameObject player;
    [SerializeField] private GameObject textNPC;

    [Header("Sounds")]
    [SerializeField] private AudioClip NPCSound;

    private void Awake()
    {
        textNPC.SetActive(false);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.tag == "Player")
        {
            SoundManager.instance.PlaySound(NPCSound);
            textNPC.SetActive(true);
            player.GetComponent<PlayerMovement>().enabled = false;
        }
    }
}
