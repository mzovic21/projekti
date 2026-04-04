using UnityEngine;
using UnityEngine.UI;

public class ShardOfLight : MonoBehaviour
{
    [SerializeField] private int value;
    [SerializeField] public GameObject UICanvas;

    [Header("Sounds")]
    [SerializeField] private AudioClip shardOfLightSound;

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.tag == "Player")
        {
            SoundManager.instance.PlaySound(shardOfLightSound);
            UICanvas.GetComponent<UIManager>().addShard(value);
            Destroy(gameObject);
        }

    }
}
