using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneController : MonoBehaviour
{
    public void Restart()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
        Time.timeScale = 1;
    }

    public void MainMenu()
    {
        SceneManager.LoadScene(0);
        Time.timeScale = 1;
    }

    public void Quit()
    {
        Application.Quit(); // radi samo na build opciji

        #if UNITY_EDITOR
                UnityEditor.EditorApplication.isPlaying = false; // izlaz iz play moda u editoru
        #endif
    }

    public void Play()
    {
        SceneManager.LoadScene(2);
    }

    public void Credits()
    {
        SceneManager.LoadScene(1);
    }
}
