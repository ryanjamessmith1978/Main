// *** CameraController ***
// This class is for the cameras 
// by Ryan J Smith

using UnityEngine;
using System.Collections;

public class CameraController : MonoBehaviour {

    private Vector3 offset;
    public Transform playerPosition;

	// Use this for initialization
	void Start () {

        // creates a constant offset distance between the player and the camera, doesn't rotate with player
        offset = transform.position - playerPosition.transform.position;

    }
	
	// Update is called once per frame
	void FixedUpdate () {        
        
        // updates that offset every frame to it follows player at steady pace
        transform.position = playerPosition.transform.position + offset;	
	}

    public void SetPlayerPosition(Transform pTransform)
    {
        playerPosition = pTransform;
        
    }
}
