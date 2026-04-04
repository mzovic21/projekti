using UnityEngine;

public class Market : MonoBehaviour
{
    [SerializeField] private GameObject player;
    [SerializeField] private GameObject shopText;
    [SerializeField] private GameObject UICanvas;
    [SerializeField] private int removePumpkin;
    [SerializeField] private int addShards;

    [Header("Sounds")]
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
                if(UICanvas.GetComponent<UIManager>().pumpkinAmount >= removePumpkin) 
                {
                    SoundManager.instance.PlaySound(yesChoice);
                    UICanvas.GetComponent<UIManager>().removePumpkin(removePumpkin);
                    UICanvas.GetComponent<UIManager>().addShard(addShards);
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
            shopText.SetActive(true);
    }
}
