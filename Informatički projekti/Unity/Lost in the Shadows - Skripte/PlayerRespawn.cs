using UnityEngine;
using UnityEngine.Rendering.Universal;

public class PlayerRespawn : MonoBehaviour
{
    private Transform currentCheckpoint;
    private PlayerHealth playerHealth;
    [SerializeField] private GameObject lightOfPast;

    private void Awake()
    {
        playerHealth = GetComponent<PlayerHealth>();
    }
    /*
    public void SpawnLight()
    {
        GameObject light = new GameObject();
        light.name = "Light of the past";
        light.transform.position = transform.position;
        light.layer = 10;
        light.AddComponent<Light2D>();
        light.GetComponent<Light2D>().pointLightOuterRadius = 2;
        light.GetComponent<Light2D>().color = GetComponent<Light2D>().color;
        light.transform.parent = lightOfPast.transform;
    }
    */
    public void Respawn()
    {
        transform.position = currentCheckpoint.position;
        playerHealth.Respawn();
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.tag == "Checkpoint")
        {
            if(currentCheckpoint) currentCheckpoint.GetComponent<Light2D>().enabled = false;
            currentCheckpoint = collision.transform;
            collision.GetComponent<Light2D>().enabled = true;
        }
    }
}
