/*
 * Greg St. Angelo IV
 * GAME JAM 2016
 * 
 * 11.4.2016
 */
using UnityEngine;
using UnityEngine.SceneManagement;

/// <summary>
/// Manages levels and enforces a singleton pattern.
/// </summary>
public class LevelManager : MonoBehaviour
{
    private static int levelIndex = 0;

    /// <summary>
    /// Attempts to setup a scene --
    /// and will catch all generic system exceptions, then return false if caught.
    /// </summary>
    /// <param name="index">integer representation of the scene to load</param>
    /// <returns>true if successful, and false if not</returns>
    public bool SetupScene(int index)
    {
        try
        {
            // if the index is valid based on the current build settings
            if(index <= SceneManager.sceneCountInBuildSettings - 1)
            {
                levelIndex = index;
                SceneManager.LoadScene(levelIndex);
                return true;
            }
            else // if the index is not in the current build
            {
                Debug.Log("Scene index out of range.");
                return false;
            }
        }
        catch(System.Exception e)
        {
            // print any errors caught
            Debug.Log(e.Message);
            return false;
        }
    }
}
