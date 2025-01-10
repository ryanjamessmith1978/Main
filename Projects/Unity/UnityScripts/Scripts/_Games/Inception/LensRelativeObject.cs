/*
 * Greg St. Angelo IV
 * GAME JAM 2016
 * 
 * 11.4.2016
 */
using UnityEngine;
using System.Collections;

/// <summary>
/// Handles objects that should change based on lens color.
/// </summary>
public class LensRelativeObject : MonoBehaviour
{
    public OverlayShader os;

    // Use this for initialization
    void Start ()
    {
        transform.root.GetComponentInChildren<MeshRenderer>().enabled = false;
        transform.root.GetComponentInChildren<Collider>().enabled = false;
    }
	
	// Update is called once per frame
	void Update ()
    {
        CheckLensState();
    }

    /// <summary>
    /// Handles disappearing objects.
    /// </summary>
    void CheckLensState()
    {
        // red stuff
        if (os.redOverlay.activeInHierarchy)
        {
            Debug.Log("Red Overlay is active.");
        }

        if (transform.root.tag == "Red" && os.redOverlay.activeInHierarchy)
        {
            transform.root.GetComponentInChildren<MeshRenderer>().enabled = true;
            transform.root.GetComponentInChildren<Collider>().enabled = true;
        }
        else if (transform.root.tag == "Red" && !os.redOverlay.activeInHierarchy)
        {
            transform.root.GetComponentInChildren<MeshRenderer>().enabled = false;
            transform.root.GetComponentInChildren<Collider>().enabled = false;
        }

        // blue stuff
        if (os.blueOverlay.activeInHierarchy)
        {
            Debug.Log("Blue Overlay is active.");
        }

        if (transform.root.tag == "Blue" && os.blueOverlay.activeInHierarchy)
        {
            transform.root.GetComponentInChildren<MeshRenderer>().enabled = true;
            transform.root.GetComponentInChildren<Collider>().enabled = true;
        }
        else if (transform.root.tag == "Blue" && !os.blueOverlay.activeInHierarchy)
        {
            transform.root.GetComponentInChildren<MeshRenderer>().enabled = false;
            transform.root.GetComponentInChildren<Collider>().enabled = false;
        }

        // green stuff
        if (os.greenOverlay.activeInHierarchy)
        {
            Debug.Log("Green Overlay is active.");
        }

        if (transform.root.tag == "Green" && os.greenOverlay.activeInHierarchy)
        {
            transform.root.GetComponentInChildren<MeshRenderer>().enabled = true;
            transform.root.GetComponentInChildren<Collider>().enabled = true;
        }
        else if (transform.root.tag == "Green" && !os.greenOverlay.activeInHierarchy)
        {
            transform.root.GetComponentInChildren<MeshRenderer>().enabled = false;
            transform.root.GetComponentInChildren<Collider>().enabled = false;
        }
    }
}
