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
    private int numOfPlayers = 0;

    // Objects that will load in scene section
    private GameObject player1;
    private GameObject player2;
    private GameObject player3;
    private GameObject player4;

    private GameObject camera1;
    private GameObject camera2;
    private GameObject camera3;
    private GameObject camera4;

    // Prefabs of where the objects were, 
    // and the components they have in the initial scene
    public GameObject Camera1Prefab = null;
    public GameObject Player1Prefab = null;
    public Transform Camera1Transform = null;
    public Transform Player1Position = null;

    public GameObject Camera2Prefab = null;
    public GameObject Player2Prefab = null;
    public Transform Camera2Transform = null;
    public Transform Player2Position = null;

    public GameObject Camera3Prefab = null;
    public GameObject Player3Prefab = null;
    public Transform Camera3Transform = null;
    public Transform Player3Position = null;

    public GameObject Camera4Prefab = null;
    public GameObject Player4Prefab = null;
    public Transform Camera4Transform = null;
    public Transform Player4Position = null;

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
           
            // then destroys the new GameController object created
            DestroyImmediate(this.gameObject);
            return;
        }        
           
        // Initial assignment of the GameController to an instance of itself
        instance = this;
        
        // Sets this instance of the initial GameController to not destroy on load when reloading level or a new scene
        DontDestroyOnLoad(this.gameObject);
        
    }

    // resets the scene upon start
    void Start ()
    {
        // ResetScene();  
        Debug.Log(numOfPlayers);
    }
	
	// Update is called once per frame
	void Update ()
    {
        
     
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
       
    }

    // This is actually set in the menu script on the title screen
    // Whichever button is pressed sets the corresponding number of players
    public void SetNumberOfPlayers(int players)
    {
        numOfPlayers = players;
        Debug.Log(numOfPlayers);
       
        // uses a switch to load different functionality based on number of players
        switch(numOfPlayers)
        {
            case 1:
                LoadOnePlayer();        
            break;

            case 2:
                LoadTwoPlayers();
            break;

            case 3:
                LoadThreePlayers();
            break;

            case 4:
            default:
                LoadFourPlayers();
            break;
        }

    }

    // *** Multiplayer Presets ***
    // Instantiates the objects in the world based on spawn points put in the scene
    // Make sure not to destroy on load when transition to new scene
    // changes the camera's Rect Struct to change the size in relation to the screen

    // loads 1 player preset
    void LoadOnePlayer()
    {
        ResetScene();
        camera1 = Instantiate(Camera1Prefab, Camera1Transform.position, Camera1Transform.rotation) as GameObject;
        DontDestroyOnLoad(camera1);
        camera1.GetComponent<Camera>().rect = new Rect(0, 0, 1, 1);
        CameraController camControl1 = camera1.GetComponent<CameraController>();

        player1 = Instantiate(Player1Prefab, Player1Position.position, Player1Position.rotation) as GameObject;
        DontDestroyOnLoad(player1);
        camControl1.SetPlayerPosition(player1.transform);
    }

    // loads 2 players preset
    void LoadTwoPlayers()
    {
        ResetScene();
        camera1 = Instantiate(Camera1Prefab, Camera1Transform.position, Camera1Transform.rotation) as GameObject;
        camera2 = Instantiate(Camera2Prefab, Camera2Transform.position, Camera2Transform.rotation) as GameObject;
        DontDestroyOnLoad(camera1);
        DontDestroyOnLoad(camera2);
        camera1.GetComponent<Camera>().rect = new Rect(0, 0.5f, 1.0f, .5f);
        camera2.GetComponent<Camera>().rect = new Rect(0, 0, 1.0f, .5f);

        CameraController camControl1 = camera1.GetComponent<CameraController>();
        CameraController camControl2 = camera2.GetComponent<CameraController>();

        player1 = Instantiate(Player1Prefab, Player1Position.position, Player1Position.rotation) as GameObject;
        DontDestroyOnLoad(player1);
        player2 = Instantiate(Player2Prefab, Player2Position.position, Player2Position.rotation) as GameObject;
        DontDestroyOnLoad(player2);

        camControl1.SetPlayerPosition(player1.transform);
        camControl2.SetPlayerPosition(player2.transform);

    }

    // loads 3 players preset
    void LoadThreePlayers()
    {
        ResetScene();
        camera1 = Instantiate(Camera1Prefab, Camera1Transform.position, Camera1Transform.rotation) as GameObject;
        camera2 = Instantiate(Camera2Prefab, Camera2Transform.position, Camera2Transform.rotation) as GameObject;
        camera3 = Instantiate(Camera3Prefab, Camera3Transform.position, Camera3Transform.rotation) as GameObject;
        DontDestroyOnLoad(camera1);
        DontDestroyOnLoad(camera2);
        DontDestroyOnLoad(camera3);
        camera1.GetComponent<Camera>().rect = new Rect(0, 0.5f, 0.5f, 0.5f);
        camera2.GetComponent<Camera>().rect = new Rect(0.5f, 0.5f, 0.5f, 0.5f);
        camera3.GetComponent<Camera>().rect = new Rect(0, 0, 0.5f, .5f);

        CameraController camControl1 = camera1.GetComponent<CameraController>();
        CameraController camControl2 = camera2.GetComponent<CameraController>();
        CameraController camControl3 = camera3.GetComponent<CameraController>();

        player1 = Instantiate(Player1Prefab, Player1Position.position, Player1Position.rotation) as GameObject;
        DontDestroyOnLoad(player1);
        player2 = Instantiate(Player2Prefab, Player2Position.position, Player2Position.rotation) as GameObject;
        DontDestroyOnLoad(player2);
        player3 = Instantiate(Player3Prefab, Player3Position.position, Player3Position.rotation) as GameObject;
        DontDestroyOnLoad(player3);

        camControl1.SetPlayerPosition(player1.transform);
        camControl2.SetPlayerPosition(player2.transform);
        camControl3.SetPlayerPosition(player3.transform);
    }

    // loads 4 players preset
    void LoadFourPlayers()
    {
        ResetScene();
        camera1 = Instantiate(Camera1Prefab, Camera1Transform.position, Camera1Transform.rotation) as GameObject;
        camera2 = Instantiate(Camera2Prefab, Camera2Transform.position, Camera2Transform.rotation) as GameObject;
        camera3 = Instantiate(Camera3Prefab, Camera3Transform.position, Camera3Transform.rotation) as GameObject;
        camera4 = Instantiate(Camera4Prefab, Camera4Transform.position, Camera4Transform.rotation) as GameObject;
        DontDestroyOnLoad(camera1);
        DontDestroyOnLoad(camera2);
        DontDestroyOnLoad(camera3);
        DontDestroyOnLoad(camera4);
        camera1.GetComponent<Camera>().rect = new Rect(0, 0.5f, .5f, 0.5f);
        camera2.GetComponent<Camera>().rect = new Rect(0.5f, 0.5f, 0.5f, 0.5f);       
        camera3.GetComponent<Camera>().rect = new Rect(0, 0, 0.5f, 0.5f);
        camera4.GetComponent<Camera>().rect = new Rect(0.5f, 0, 0.5f, 0.5f);

        CameraController camControl1 = camera1.GetComponent<CameraController>();
        CameraController camControl2 = camera2.GetComponent<CameraController>();
        CameraController camControl3 = camera3.GetComponent<CameraController>();
        CameraController camControl4 = camera4.GetComponent<CameraController>();

        player1 = Instantiate(Player1Prefab, Player1Position.position, Player1Position.rotation) as GameObject;
        DontDestroyOnLoad(player1);
        player2 = Instantiate(Player2Prefab, Player2Position.position, Player2Position.rotation) as GameObject;
        DontDestroyOnLoad(player2);
        player3 = Instantiate(Player3Prefab, Player3Position.position, Player3Position.rotation) as GameObject;
        DontDestroyOnLoad(player3);
        player4 = Instantiate(Player4Prefab, Player4Position.position, Player4Position.rotation) as GameObject;
        DontDestroyOnLoad(player4);

        camControl1.SetPlayerPosition(player1.transform);
        camControl2.SetPlayerPosition(player2.transform);
        camControl3.SetPlayerPosition(player3.transform);
        camControl4.SetPlayerPosition(player4.transform);

    }
}
