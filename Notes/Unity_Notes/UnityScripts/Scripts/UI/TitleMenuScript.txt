// *** MenuScript class ***
// This class is for the title screen 
// by Ryan J Smith

using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
using System.Collections;


public class menuScript : MonoBehaviour {

    
    // Canvas variables
    public Canvas StartMenu;
    public Canvas quitMenu;
    public Canvas playerMenu;
    public Button startText;
    public Button exitText;
    public Button yesText;
    public Button One;
    public Button Two;
    public Button Three;
    public Button Four;    

    void Start ()
    {
       
        // grabs the components of the UI
        playerMenu = playerMenu.GetComponent<Canvas>();
        quitMenu = quitMenu.GetComponent<Canvas>();
        startText = startText.GetComponent<Button>();
        exitText = exitText.GetComponent<Button>();

        // makes the quit and player selection menus not visible at the start
        quitMenu.enabled = false;
        playerMenu.enabled = false;

        // makes the text selectable via controller
        startText.Select();
        exitText.Select();
    }
	
	// Update is called once per frame
	void Update ()
    {

    }

    // When you hit the Exit Button, an additional exit menu comes up
    public void ExitPress()
    {
        quitMenu.enabled = true;
        startText.enabled = false;
        exitText.enabled = false;
        yesText.Select();
    }

    // When you accidentally hit exit game, but then decide to return the title screen
    public void NoPress()
    {
        quitMenu.enabled = false;
        startText.enabled = true;
        exitText.enabled = true;
    }

    // loads the main demo level
    public void StartLevel()
    {      
        SceneManager.LoadScene("testScene");
    }

    // quits the game
    public void ExitGame()
    {
        Application.Quit();
    }

    // loads player window to choose number of players
    public void LoadPlayerMenu()
    {
        startText.enabled = false;
        exitText.enabled = false;
        playerMenu.enabled = true;
        One.Select();
        Two.Select();
        Three.Select();
        Four.Select();
    }

    // Sets the game mode for One Player
    public void ButtonOneClicked()
    {
        disableStartMenu();
       // Camera.main.gameObject.SetActive(false);
        GameController.GetInstance.SetNumberOfPlayers(1);        
    }

    // Sets the game mode for Two Players
    public void ButtonTwoClicked()
    {
        disableStartMenu();
        //Camera.main.gameObject.SetActive(false);
        GameController.GetInstance.SetNumberOfPlayers(2);
      
    }
    
    // Sets the game mode for Three Players
    public void ButtonThreeClicked()
    {
        disableStartMenu();
       // Camera.main.gameObject.SetActive(false);
        GameController.GetInstance.SetNumberOfPlayers(3);
       
    }

    // Sets the game mode for 4 players
    public void ButtonFourClicked()
    {
        disableStartMenu();
        //Camera.main.gameObject.SetActive(false);
        GameController.GetInstance.SetNumberOfPlayers(4);        
    }

    public void disableStartMenu()
    {
        playerMenu.enabled = false;
        StartMenu.enabled = false;
    }
}
