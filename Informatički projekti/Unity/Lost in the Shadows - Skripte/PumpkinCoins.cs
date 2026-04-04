using UnityEngine;
using UnityEngine.UI;

public class PumpkinCoins : MonoBehaviour
{
    [SerializeField] private int value;
    [SerializeField] private GameObject UICanvas;

    [Header("Sounds")]
    [SerializeField] private AudioClip coinSound;

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.tag == "Player")
        {
            SoundManager.instance.PlaySound(coinSound);
            UICanvas.GetComponent<UIManager>().addPumpkin(value);
            Destroy(gameObject);
        }
            
    }
}
