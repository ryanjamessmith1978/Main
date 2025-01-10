/*
 * Greg St. Angelo IV
 * GAME JAM 2016
 * 
 * 11.4.2016
 */
using UnityEngine;

/// <summary>
/// Collects objects collided with players.
/// </summary>
public class Collectable : MonoBehaviour
{
    // reference to the games input manager
    InputManager im;

    /// <summary>
    /// Finds the current input manager of the game.
    /// </summary>
    void Awake()
    {
        // works because of singleton pattern
        im = FindObjectOfType<InputManager>();
    }

    /// <summary>
    /// Handles trigger entry events.
    /// </summary>
    /// <param name="other"></param>
	void OnTriggerEnter(Collider other)
    {
        // check if a player hit this object
        if(other.transform.root.tag == "Player")
        {
            switch (transform.root.tag)
            {
                case "Red":
                    Debug.Log("Now allowing red.");
                    im.redAllow = true;
                    break;
                case "Blue":
                    Debug.Log("Now allowing blue.");
                    im.blueAllow = true;
                    break;
                case "Green":
                    Debug.Log("Now allowing green.");
                    im.greenAllow = true;
                    break;
                default:
                    break;
            }
            Destroy(gameObject);
        }
    }
}
