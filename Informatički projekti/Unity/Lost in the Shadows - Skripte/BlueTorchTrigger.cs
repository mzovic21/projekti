using UnityEngine;

public class BlueTorchTrigger : MonoBehaviour
{
    [SerializeField] private GameObject player;
    [SerializeField] private GameObject blueTorchHolder;
    [SerializeField] private GameObject UICanvas;

    private void Awake()
    {
        blueTorchHolder.SetActive(false);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.tag == "Player")
        {
            blueTorchHolder.SetActive(true);
            UICanvas.GetComponent<UIManager>().blueTorch.SetActive(true);
        }
    }
}
