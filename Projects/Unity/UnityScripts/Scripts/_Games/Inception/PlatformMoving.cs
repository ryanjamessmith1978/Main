/*
 * Greg St. Angelo IV
 * GAME JAM 2016
 * 
 * 11.4.2016
 */
using UnityEngine;

/// <summary>
/// Moves platforms between two points.
/// </summary>
public class PlatformMoving : MonoBehaviour
{
    public GameObject pointA, pointB;

    public bool sideToSide = false, upAndDown = false;

    private bool moveToA = true;

    /// <summary>
    /// Updates the platform object.
    /// </summary>
    void Update()
    {
        if (sideToSide)
        {
            upAndDown = false;
        }

        if (upAndDown){
            sideToSide = false;
        }
    }

    /// <summary>
    /// Handles translation of platforms.
    /// </summary>
    void FixedUpdate()
    {
        if (sideToSide)
        {
            // swap directions if they have gone too far past point A
            if (transform.position.x < pointA.transform.position.x && moveToA)
               moveToA = !moveToA;

            // swap directions if they have gone too far past point B
            if (transform.position.x > pointB.transform.position.x && !moveToA)
                moveToA = !moveToA;


            // move the entire prefab toward point A
            if (transform.position.x > pointA.transform.position.x && moveToA)
            {
                transform.Translate(-Vector3.right * Time.deltaTime);
            }

            // move the entire prefab toward point B
            if (transform.position.x < pointB.transform.position.x && !moveToA)
            {
                transform.Translate(Vector3.right * Time.deltaTime);
            }
        }

        if (upAndDown)
        {
            // swap directions if they have gone too far past point A
            if (transform.position.y > pointA.transform.position.y && moveToA)
                moveToA = !moveToA;

            // swap directions if they have gone too far past point B
            if (transform.position.y < pointB.transform.position.y && !moveToA)
                moveToA = !moveToA;


            // move the entire prefab toward point A
            if (transform.position.y < pointA.transform.position.y && moveToA)
            {
                transform.Translate(Vector3.up * Time.deltaTime);
            }

            // move the entire prefab toward point B
            if (transform.position.y > pointB.transform.position.y && !moveToA)
            {
                transform.Translate(Vector3.down * Time.deltaTime);
            }
        }
    }
}
