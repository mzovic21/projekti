using UnityEngine;

public class Statue : MonoBehaviour
{
    [SerializeField] private GameObject player;
    [SerializeField] private GameObject shopText;
    [SerializeField] private GameObject UICanvas;
    [SerializeField] private int removePumpkins;
    [SerializeField] private GameObject shardSpawner;

    [Header("Sounds")]
    [SerializeField] private AudioClip statueSound;
    [SerializeField] private AudioClip yesChoice;
    [SerializeField] private AudioClip noChoice;

    private void Awake()
    {
        shopText.SetActive(false);
    }

    private void Update()
    {
        if (shopText.activeInHierarchy)
        {
            player.GetComponent<PlayerMovement>().enabled = false;
            if (Input.GetKeyDown(KeyCode.Y) || Input.GetKeyDown(KeyCode.Z))
            {
                if (UICanvas.GetComponent<UIManager>().pumpkinAmount >= removePumpkins)
                {
                    SoundManager.instance.PlaySound(yesChoice);
                    UICanvas.GetComponent<UIManager>().removePumpkin(removePumpkins);
                    shardSpawner.GetComponent<RandomSpawner>().activated = true;
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
        if (collision.tag == "Player")
        {
            SoundManager.instance.PlaySound(statueSound);
            shopText.SetActive(true);
        }
            
    }
}
