using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class Pause : MonoBehaviour
{
    public GameObject panel;
    public bool paused = false;

    void Update()
    {
        if (!paused)
        {
            if (Input.GetKeyUp(KeyCode.Escape))
                PauseGame();
        }
        else if (paused)
        {
            if (Input.GetKeyUp(KeyCode.Escape))
                ResumeGame();
        }
    }

    void PauseGame()
    {
	    paused = true;
	    Time.timeScale = 0.0f;
	    panel.SetActive(true);
    }
    void ResumeGame()
    {
	    Time.timeScale = 1.0f;
	    panel.SetActive(false);
        paused = false;
    }

    public void RestartGame()
    {
		Time.timeScale = 1.0f;
	    Manager.Instance().WinReset();
	    SceneManager.LoadScene(0);
    }
	public void ResumeBtn()
	{
		ResumeGame ();
	}
    public void Quit()
    {
	    Application.Quit();
    }

}


//rend.material.shader = shader2