/*
 * Greg St. Angelo IV
 * GAME JAM 2016
 * 
 * 11.4.2016
 */
using UnityEngine;

/// <summary>
/// Manages all game related variables that must persist through instances.
/// Enforces a singleton pattern.
/// </summary>
[RequireComponent(typeof(LevelManager))]
public class GameManager : MonoBehaviour
{
    // public globals
    public static GameManager instance = null;
    public OverlayShader os;
    public Canvas hud;

    // used for checking win conditions
    bool didWin = false;

    // private globals
    private LevelManager levelManager;

    private int level = 0;

    /// <summary>
    /// Enforces singleton pattern.
    /// Always called before all other methods.
    /// </summary>
    public void Awake()
    {
        // kill this instance if it is not the proper one
        if (instance != null && instance != this)
        {
            DestroyImmediate(gameObject);
            return; // leave this method because no more logic is needed
        }

        // setup the first instance
        instance = this;

        // protect it from destruction
        DontDestroyOnLoad(gameObject);

        // instantiate level manager and overlay
        levelManager = GetComponentInChildren<LevelManager>();
        os = GetComponentInChildren<OverlayShader>();
    }

    /// <summary>
    /// Setter for scene management.
    /// </summary>
    /// <param name="sceneIndex">integer representation of the scene to leoad</param>
    public void LoadScene(int sceneIndex)
    {
        level = sceneIndex;
        if (levelManager.SetupScene(level))
        {
            Debug.Log("Successfully loaded level " + level);
        }
        else
        {
            Debug.Log("Failed to load level " + level);
        }
    }

    /// <summary>
    /// Getter for scene index.
    /// </summary>
    public int GetSceneIndex()
    {
        return level;
    }

    // Update is called once per frame
    void Update()
    {
        // all levels except the main menu have the HUD turned on
        if(level > 0)
        {
            Debug.Log("HUD enabled.");
            hud.gameObject.SetActive(true);
        }

        CheckForLensStateObjects();
        // handle win conditions---------------------------------------
        if (didWin)
        {
            // switch levels for different win outcomes
            switch(level)
            {
                case 0:
                    break;
                default:
                    break;
            }
        }
        // handle win conditions---------------------------------------
    }

    /// <summary>
    /// Will find any objects tagged for lens interaction
    /// </summary>
    void CheckForLensStateObjects()
    {
        /*
        // finds objects in scene
        object[] obj = FindObjectsOfType(typeof(GameObject));
        foreach (object o in obj)
        {
            GameObject g = (GameObject)o;
            if(g.transform.root.tag == "Red")
            {
                Debug.Log("Found Red object: " + g.transform.root.name);

                transform.root.transform.gameObject.SetActive(true);
            }

            if (g.transform.root.tag == "Blue")
            {
                Debug.Log("Found Blue object: " + g.transform.root.name);

                transform.root.transform.gameObject.SetActive(true);
            }

            if (g.transform.root.tag == "Green")
            {
                Debug.Log("Found Red object: " + g.transform.root.name);

                transform.root.transform.gameObject.SetActive(true);
            }
        }
        */
        
    }
}
