using UnityEngine;
using UnityEngine.SceneManagement;

public class StoneOfRecall : MonoBehaviour
{
    [SerializeField] private GameObject player;
    [SerializeField] private GameObject UICanvas;
    [SerializeField] private GameObject textEnd;
    [SerializeField] private GameObject interact;

    [Header("Sounds")]
    [SerializeField] private AudioClip stoneOfRecallSound;
    [SerializeField] private AudioClip yesChoice;
    [SerializeField] private AudioClip noChoice;

    private void Awake()
    {
        gameObject.transform.GetChild(0).gameObject.SetActive(false);
        gameObject.transform.GetChild(1).gameObject.SetActive(false);
        textEnd.SetActive(false);
        interact.SetActive(false);
    }

    private void Update()
    {
        if (UICanvas.GetComponent<UIManager>().blueTorchAmount >= 9)
        {
            gameObject.transform.GetChild(0).gameObject.SetActive(true);
            gameObject.transform.GetChild(1).gameObject.SetActive(true);
            interact.SetActive(true);
        }

        if (textEnd.activeInHierarchy)
        {
            player.GetComponent<PlayerMovement>().enabled = false;
            if (Input.GetKeyDown(KeyCode.Y) || Input.GetKeyDown(KeyCode.Z))
            {
                SoundManager.instance.PlaySound(yesChoice);
                SceneManager.LoadScene(0);
            }

            if (Input.GetKeyDown(KeyCode.N))
            {
                SoundManager.instance.PlaySound(noChoice);
                textEnd.SetActive(false);
                player.GetComponent<PlayerMovement>().enabled = true;
            }

        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.tag == "Player" && UICanvas.GetComponent<UIManager>().blueTorchAmount >= 9)
        {
            SoundManager.instance.PlaySound(stoneOfRecallSound);
            textEnd.SetActive(true);
        }
    }
}
