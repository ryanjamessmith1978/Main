using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class MenuActions : MonoBehaviour {

    //public static bool isPlaying;
    public Button pause;
    public bool isPaused;
    public GameObject pausePanel;


    public void Start()
    {
        isPaused = false;
        pause.gameObject.SetActive(false);
        pausePanel.gameObject.SetActive(false);
        GameController.Instance().playerLives = 3;
        GameController.Instance().playerHealth = 1f;
    }
    
    public void Update()
    {
        if (!isPaused)
        {
            if(Input.GetKeyDown("escape"))
            {
            isPaused = true;
            Time.timeScale = 0;
            pausePanel.SetActive(true);            
            pause.gameObject.SetActive(true);
            }
        }

        else
        {
            if (Input.GetKeyDown("escape"))
            {
                Time.timeScale = 1;
                pausePanel.SetActive(false);
                isPaused = false;
            }
        }
            
   
    }

    public void StartGame()
    {

        SceneManager.LoadScene("level1");

        foreach (Transform child in GameController.Instance().transform)
        {
            if (child.name == "Canvas")
                child.gameObject.SetActive(true);
        }

        
    }

    public void QuitGame()
    {
        
        
            Application.Quit();

            #if UNITY_EDITOR
            UnityEditor.EditorApplication.isPlaying = false;
            #endif

    }

}
