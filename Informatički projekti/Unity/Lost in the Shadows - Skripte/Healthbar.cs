using UnityEngine;
using UnityEngine.UI;

public class Healthbar : MonoBehaviour
{
    [SerializeField] private PlayerHealth playerHealth;
    [SerializeField] private Image emptyHealthbar;
    [SerializeField] private Image currentHealthbar;

    private void Start()
    {
        emptyHealthbar.fillAmount = playerHealth.currentHealth;
    }

    private void Update()
    {
        currentHealthbar.fillAmount = playerHealth.currentHealth;
    }
}
