/*
 * Greg St. Angelo IV
 * GAME JAM 2016
 * 
 * 11.4.2016
 */
using UnityEngine;
using System.Collections;

public class LevelCompletion : MonoBehaviour
{
    // Globals
    GameManager gm;

    /// <summary>
    /// Handle collision with the player.
    /// </summary>
    void OnTriggerEnter(Collider other)
    {
        if(other.transform.root.tag == "Player")
        {
            Debug.Log("Hit");
            gm.LoadScene(gm.GetSceneIndex() + 1);
        }
    }
    void Awake()
    {
        // singleton allows this to be grabbed
        gm = FindObjectOfType<GameManager>();
        
    }
	// Use this for initialization
	void Start ()
    {
	}
	
	// Update is called once per frame
	void Update ()
    {
	
	}
}
