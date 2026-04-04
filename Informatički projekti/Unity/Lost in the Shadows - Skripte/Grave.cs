using UnityEngine;

public class Grave : MonoBehaviour
{
    [SerializeField] private GameObject player;
    [SerializeField] private GameObject shopText;
    [SerializeField] private GameObject UICanvas;
    [SerializeField] private int removeShards;
    [SerializeField] private GameObject chest;
    [SerializeField] private GameObject interact;
    private bool activated = false;

    [Header("Sounds")]
    [SerializeField] private AudioClip yesChoice;
    [SerializeField] private AudioClip noChoice;

    private void Awake()
    {
        shopText.SetActive(false);
        chest.SetActive(false);
    }

    private void Update()
    {
        if (shopText.activeInHierarchy)
        {
            player.GetComponent<PlayerMovement>().enabled = false;
            if (Input.GetKeyDown(KeyCode.Y) || Input.GetKeyDown(KeyCode.Z))
            {
                if (UICanvas.GetComponent<UIManager>().shardAmount >= removeShards)
                {
                    SoundManager.instance.PlaySound(yesChoice);
                    UICanvas.GetComponent<UIManager>().removeShard(removeShards);
                    chest.SetActive(true);
                    interact.SetActive(false);
                    activated = true;
                }
                else
                    SoundManager.instance.PlaySound(noChoice);

                shopText.SetActive(false);
                player.GetComponent<PlayerMovement>().enabled = true;
            }

            if (Input.GetKeyDown(KeyCode.N))
            {
                SoundManager.instance.PlaySound(noChoice);
                shopText.SetActive(false);
                player.GetComponent<PlayerMovement>().enabled = true;
            }

        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.tag == "Player" && !activated)
            shopText.SetActive(true);
    }
}
