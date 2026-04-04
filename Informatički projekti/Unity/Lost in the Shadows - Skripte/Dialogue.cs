using System.Collections;
using UnityEngine;
using UnityEngine.UI;

public class Dialogue : MonoBehaviour
{
    [SerializeField] private GameObject player;
    [SerializeField] private Text textComponent;
    [SerializeField] private string[] lines;
    [SerializeField] private float textSpeed;

    private int index;

    private void Start()
    {
        textComponent.text = string.Empty;
        StartDialogue();
    }

    private void Update()
    {
        if(Input.GetKeyDown(KeyCode.Space))
        {
            if(textComponent.text == lines[index])
            {
                NextLine();
            }
            else
            {
                StopAllCoroutines();
                textComponent.text = lines[index];
            }
        }
    }

    private void StartDialogue()
    {
        player.GetComponent<PlayerMovement>().enabled = false;
        index = 0;
        StartCoroutine(TypeLine());
    }

    private void NextLine()
    {
        if(index < lines.Length - 1)
        {
            index++;
            textComponent.text = string.Empty;
            StartCoroutine(TypeLine());
        }
        else
        {
            gameObject.SetActive(false);
            player.GetComponent<PlayerMovement>().enabled = true;
        }
    }

    IEnumerator TypeLine()
    {
        foreach(char c in lines[index].ToCharArray())
        {
            textComponent.text += c;
            yield return new WaitForSeconds(textSpeed);
        }
    }
}
