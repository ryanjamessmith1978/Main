/*
 * Greg St. Angelo IV
 * GAME JAM 2016
 * 
 * 11.4.2016
 */
using UnityEngine;
using UnityEngine.UI;
using UnityEditor; // MUST COMMENT OUT FOR BUILDS ************************************************

/// <summary>
/// Builds a functional main menu.
/// </summary>
public class MenuScript : MonoBehaviour
{
    // public globals
    public GameManager gameManager;

    public Canvas quitMenu;
    public Button start, quit;

	// Use this for initialization
	void Start ()
    {
        quitMenu = quitMenu.GetComponent<Canvas>();

        start = start.GetComponent<Button>();
        quit = quit.GetComponent<Button>();

        start.Select(); // for controllers

        quitMenu.enabled = false;

        gameManager = FindObjectOfType<GameManager>();
    }

    /// <summary>
    /// Calls actions for when the Quit button is pressed.
    /// Loads Quit Menu.
    /// </summary>
    public void QuitButtonPressed()
    {
        quitMenu.enabled = true; // enable the quit menu
        quitMenu.GetComponentInChildren<Button>().Select(); // for controllers

        // disable regular menu buttons to avoid interference
        start.enabled = false;
        quit.enabled = false;
    }

    /// <summary>
    /// Calls actions performed when the No button is pressed in the Quit Menu.
    /// </summary>
    public void NoPressed()
    {
        quitMenu.enabled = false; // disable the quit menu

        // re-enable the regular menu buttons
        start.enabled = true;
        quit.enabled = true;

        start.Select(); // for controllers
    }

    /// <summary>
    /// Starts the game.
    /// </summary>
    public void StartGame()
    {
        // load first level
        gameManager.LoadScene(1);
    }

    /// <summary>
    /// Quits the game.
    /// </summary>
    public void QuitGame()
    {
        Application.Quit(); // for builds
        EditorApplication.isPlaying = false; // MUST COMMENT OUT FOR BUILDS ************************************************
    }

    // Update is called once per frame
    void Update ()
    {
	
	}
}
