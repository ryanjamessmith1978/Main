// *** MenuScript class ***
// This class is for the title screen 
// by Ryan J Smith

using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
using System.Collections;


public class menuScript : MonoBehaviour {

    // Canvas variables
    public Canvas quitMenu;
    public Button startText;
    public Button exitText;
   
	void Start ()
    {
        // grabs the components of the UI
        quitMenu = quitMenu.GetComponent<Canvas>();
        startText = startText.GetComponent<Button>();
        exitText = exitText.GetComponent<Button>();

        quitMenu.enabled = false;        
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
        SceneManager.LoadScene("demo_level");
    }

    // quits the game
    public void ExitGame()
    {
        Application.Quit();
    }

    

}
