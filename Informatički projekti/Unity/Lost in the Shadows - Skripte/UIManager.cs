using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class UIManager : MonoBehaviour
{
    [SerializeField] private GameObject map;
    [SerializeField] private GameObject pauseScreen;
    [SerializeField] private GameObject minimap;
    [SerializeField] private Text pumpkinText;
    [SerializeField] private Text shardText;
    [SerializeField] public GameObject blueTorch;
    [SerializeField] private Text blueTorchText;

    [Header("Sounds")]
    [SerializeField] private AudioClip mapSound;

    bool isMapOpen;
    bool isPauseScreenOpen;
    public int pumpkinAmount = 0;
    public int shardAmount = 0;
    public int blueTorchAmount = 0;

    private void Awake()
    {
        map.SetActive(false);
        pauseScreen.SetActive(false);
        blueTorch.SetActive(false);
    }

    private void Update()
    {
        if (SceneManager.GetActiveScene().name == "TestScene") 
        {
            if (Input.GetKeyDown(KeyCode.M))
            {
                SoundManager.instance.PlaySound(mapSound);

                if (isMapOpen)
                {
                    Time.timeScale = 1;
                    map.SetActive(false);
                    minimap.SetActive(true);
                }
                else
                {
                    map.SetActive(true);
                    minimap.SetActive(false);
                    Time.timeScale = 0;
                }

                isMapOpen = !isMapOpen;
            }

            if (Input.GetKeyDown(KeyCode.P) || Input.GetKeyDown(KeyCode.Escape))
            {
                SoundManager.instance.PlaySound(mapSound);

                if (isPauseScreenOpen)
                {
                    pauseScreen.SetActive(false);
                    Time.timeScale = 1;
                }
                else
                {
                    pauseScreen.SetActive(true);
                    Time.timeScale = 0;
                }

                isPauseScreenOpen = !isPauseScreenOpen;
            }
        }
   
    }

    public void addPumpkin(int value)
    {
        pumpkinAmount += value;
        pumpkinText.text = pumpkinAmount.ToString();
    }

    public void addShard(int value)
    {
        shardAmount += value;
        shardText.text = shardAmount.ToString();
    }

    public void removePumpkin(int value)
    {
        pumpkinAmount -= value;
        pumpkinText.text = pumpkinAmount.ToString();
    }

    public void removeShard(int value)
    {
        shardAmount -= value;
        shardText.text = shardAmount.ToString();
    }

    public void countBlueTorch()
    {
        blueTorchAmount++;
        blueTorchText.text = blueTorchAmount.ToString();
        blueTorchText.text = string.Format("{0}/9", blueTorchAmount);
    }
}
