using UnityEngine;

public class BlueTorch : MonoBehaviour
{
    [SerializeField] private GameObject player;
    [SerializeField] private GameObject UICanvas;

    [Header("Sounds")]
    [SerializeField] private AudioClip blueTorchSound;

    private bool activated;

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.tag == "Player" && !activated)
        {
            SoundManager.instance.PlaySound(blueTorchSound);
            gameObject.transform.GetChild(0).gameObject.SetActive(false);
            gameObject.transform.GetChild(1).gameObject.SetActive(true);
            gameObject.transform.GetChild(2).gameObject.SetActive(true);
            gameObject.transform.GetChild(3).gameObject.SetActive(true);
            gameObject.transform.GetChild(4).gameObject.SetActive(true);

            UICanvas.GetComponent<UIManager>().countBlueTorch();
            activated = true;
        }
    }
}
