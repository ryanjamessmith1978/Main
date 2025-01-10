/*
 * Greg St. Angelo IV
 * GAME JAM 2016
 * 
 * 11.4.2016
 */
using UnityEngine;

/// <summary>
/// Parents the platform to the player
/// </summary>
public class CharacterHolder : MonoBehaviour
{
    /// <summary>
    /// Handles collision events.
    /// </summary>
    /// <param name="other">colliding object</param>
    void OnTriggerEnter(Collider other)
    {
        Debug.Log("You hit the platform.");
        other.transform.parent = transform;
    }

    /// <summary>
    /// Handles collision leave events.
    /// </summary>
    /// <param name="other">colliding object</param>
    void OnTriggerExit(Collider other)
    {
        Debug.Log("You left the platform.");
        other.transform.parent = null;
    }
}
