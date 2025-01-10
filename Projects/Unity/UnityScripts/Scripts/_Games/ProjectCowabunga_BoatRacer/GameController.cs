// *** GameController class ***
// Creates a persistent stat GameController that stores persistent values, and sets the rules for the game
// GameController is also responsible for the primary UI of the game.
// by Ryan J Smith

using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

// GameController Singleton 
public class GameController : MonoBehaviour {

    // Creates a static instance of this class and sets it to null
    private static GameController instance = null;           
    // stores a static instance of the best time
    private static float bestTime;

    // instance of the boat controller (player controller) that is actually set by the boat controller script itself (thanks :))
    public BoatController BC;
    // displays the best time in the UI
    public Text BestTime;
    // creates a text variable to display the current time
    public Text Timer;
    // creates a text in the UI to display finished if crossing the finish line
    public Text Finish;
    // Speed Text
    public Text Speed;
    // creates a slider bar to display the current turbo meter value
    public Slider TurboSlider;
    // stores the Turbo value of the player into this float which is displayed by the Turbo slider in this UI
    public float TurboMeter;
    // stores the value of the current time for how long the player has been racing    
    private float time;

    // static function for returning the correct instance of the GameController
    public static GameController GetInstance
    {
        get { return instance; }
    }

    // Function called immediately when game starts
    void Awake()
    {
        // checks if the instance is already loaded into the scene (upon crossing finish and reloading level)
        if (instance != null && instance != this)
        {   
            // if the GameController is already loaded in the scene, it stores the best time value                   
            BestTime.text = "Best Time: " + bestTime.ToString("#00");
            // then destroys the new GameController object created
            DestroyImmediate(this.gameObject);
            return;
        }
        
        // For the first time when pressing Play, these initial GameController values are set, including that static instance of the GameController itself           
        bestTime = 120f;
        BestTime.text = null;
        // Initial assignment of the GameController to an instance of itself
        instance = this;
        // Sets this instance of the initial GameController to not destroy on load when reloading level or a new scene
        DontDestroyOnLoad(this.gameObject);
    }

    // resets the scene upon start
    void Start ()
    {        
        ResetScene();        
    }
	
	// Update is called once per frame
	void Update ()
    {
        // Adds delta time to the time accumulated during the race
        time = time + Time.deltaTime;
        // Puts that time value into the Time text variable of the primary UI
        Timer.text = "TIME: " + time.ToString("#00");
        // Updates the turbo meter value from the player
        TurboSlider.value = BC.GetTurbo();
        // gets speed to display on UI
        Speed.text = "Speed:     " + BC.GetSpeed().ToString();

        // Checks to see if the player has crossed the finish time
        if (BC.HasCrossedFinish())
        {            
            // Checks to see if the current time is less that overall best time
            if (time < bestTime)
            {
                // If the current time is less than best time, you set a new best time
                bestTime = time;
                // Displays new best time on screen
                BestTime.text = "Best Time: " + bestTime.ToString("#00");
            }        
        }
	}

    // Resets scene and loads level
    public void ResetScene()
    {        
        ResetUI();        
        SceneManager.LoadScene(1);
    }

    // Resets the UI to its initial values
    void ResetUI()
    {        
        TurboMeter = 1.0f;
        time = 0f;
        Timer.text = "TIME: " + time.ToString("#00");
        Finish.text = "";
        Speed.text = "Speed:     " + BC.GetSpeed().ToString();
    }

    // Sets finish to display the text on screen
    public void SetFinish()
    {
        Finish.text = "FINISH";
    }

}
