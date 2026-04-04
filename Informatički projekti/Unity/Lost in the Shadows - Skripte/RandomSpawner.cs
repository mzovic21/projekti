using UnityEngine;
using UnityEngine.Rendering.UI;
using UnityEngine.UI;

public class RandomSpawner : MonoBehaviour
{
    [SerializeField] private GameObject itemPrefab;
    [SerializeField] private GameObject text;
    [SerializeField] private float radius;
    [SerializeField] private float timeRemaining = 0;
    [SerializeField] private Text timeText;
    private bool timeIsRunning;
    public bool activated = false;
    [SerializeField] private int numberOfShards;

    private void Awake()
    {
        text.SetActive(false);
    }

    public void Update()
    {
        if (activated)
        {
            for(int i = 0; i < numberOfShards; i++)
                SpawnObject();

            activated = false;
        }
            

        if (timeRemaining < 0)
        {
            Destroy(GameObject.Find("Shard of Light(Clone)"));
            text.SetActive(false);
            timeIsRunning = false;
        }

        if (timeIsRunning)
        {
            timeRemaining -= Time.deltaTime;
            DisplayTime(timeRemaining);
        }
            
    }

    private void SpawnObject()
    {
        Vector3 randomPosition = Random.insideUnitCircle * radius;

        Instantiate(itemPrefab, randomPosition, Quaternion.identity);
        timeIsRunning = true;
        text.SetActive(true);
        itemPrefab.GetComponent<ShardOfLight>().UICanvas = GameObject.Find("UICanvas");
        timeRemaining = 75;

    }

    private void DisplayTime(float timeToDisplay)
    {
        timeToDisplay += 1;
        float minutes = Mathf.FloorToInt(timeToDisplay / 60);
        float seconds = Mathf.FloorToInt(timeToDisplay % 60);
        timeText.text = string.Format("{0:00}:{1:00}", minutes, seconds);
    }



    private void OnDrawGizmos()
    {
        Gizmos.color = Color.red;
        Gizmos.DrawWireSphere(this.transform.position, radius);
    }
}
