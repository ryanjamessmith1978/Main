// *** PauseGame class ***
// Loads a pause screen
// by Ryan J Smith


using UnityEngine;
using UnityEngine.SceneManagement;
using System.Collections;

// Pause Game class begins
public class PauseGame : MonoBehaviour {

    // transform and canvas variables
    public Transform PauseCanvas;
    public Canvas PauseMenu;

	void Start()
    {
        // Gets canvas from the attached script
        PauseMenu = PauseMenu.GetComponent<Canvas>();
    }

	// Update is called once per frame
	void Update ()
    {
	    // pauses game when escape is pressed
        if(Input.GetKeyDown(KeyCode.Escape))
        {
            Pause();
        }
	}

    // Pause function that pauses the game and loads a pause menu
    public void Pause()
    {
        if (PauseCanvas.gameObject.activeInHierarchy == false)
        {
            PauseCanvas.gameObject.SetActive(true);
            Time.timeScale = 0;
        }
        else
        {
            PauseCanvas.gameObject.SetActive(false);
            Time.timeScale = 1;
        }
    }

    // Allows the player to exit the game from the pause screen
    public void ExitToMainMenu()
    {
        SceneManager.LoadScene("Title_Screen");
    }
}
