using UnityEngine;

public class Hammer : MonoBehaviour
{
    [SerializeField] private GameObject player;
    [SerializeField] private GameObject chest;
    [SerializeField] private GameObject text;

    [Header("Sounds")]
    [SerializeField] private AudioClip pickupSound;

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.tag == "Player")
        {
            SoundManager.instance.PlaySound(pickupSound);
            text.SetActive(true);
            chest.GetComponent<ChestGold>().hammer = true;
            Destroy(gameObject);
        }
    }
}
