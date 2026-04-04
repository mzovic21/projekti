using UnityEngine;

public class Bucket : MonoBehaviour
{
    [SerializeField] private GameObject player;
    [SerializeField] private GameObject well;
    [SerializeField] private GameObject text;

    [Header("Sounds")]
    [SerializeField] private AudioClip pickupSound;

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.tag == "Player")
        {
            SoundManager.instance.PlaySound(pickupSound);
            text.SetActive(true);
            well.GetComponent<Well>().bucket = true;
            Destroy(gameObject);
        }
    }
}
