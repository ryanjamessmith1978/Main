// *** PlayerInput class ***
// This class is for the actual buttons pressed specific to the local player
// by Ryan J Smith

using UnityEngine;
using System.Collections;

public class PlayerInputController : MonoBehaviour {

    // gets a copy of the players logic script to separate the logic from the input
    public PlayerLogic playerLogic;
    // one logic script that passes in a single number to differentiate among which player number is loaded
    public string ControlName;
    // baseline speed
    public float PlayerSpeed = 11.75f;
    // Location of the cameraTransform in order to have movement be in relation to the which direction the camera is pointing
    public Transform cameraTransform;


	// Use this for initialization
	void Start ()
    {
	    if (playerLogic == null)
        {
            playerLogic = GetComponent<PlayerLogic>();
        }
	}

    // Physics calculations
    void FixedUpdate()
    {
        PlayerMove();
        PlayerJump();
    }

    // Player can jump when on the ground only
    void PlayerJump()
    {
        int layerMask = 1 << 9;
        Vector3 rayStart = playerLogic.transform.position;
        Vector3 rayEnd = Vector3.down;

        if (Input.GetButtonDown("Jump" + ControlName) && Physics.Raycast(rayStart, rayEnd, .6f, layerMask))
        {
            playerLogic.Jump();
        }
    }

    // player movement based on orientation of the camera
    // SOH-CAH-TOA (nah, I just looked up the script :) )
    public void PlayerMove()
    {
        Vector3 forward = cameraTransform.TransformDirection(Vector3.forward);
        forward.y = 0f;
        forward = forward.normalized;
        Vector3 right = new Vector3(forward.z, 0.0f, -forward.x);
        float h = Input.GetAxis("Horizontal" + ControlName);
        float v = Input.GetAxis("Vertical" + ControlName);
        Vector3 movement = (h * right + v * forward).normalized;
        movement *= PlayerSpeed;
        playerLogic.Move(movement);
    }

}

/*
    Vector3 forward = cameraTransform.TransformDirection(Vector3.forward)
    forward.y = 0;
    forward = forward.Normalized;
    Vector3 right = new Vector3 (forward.z, 0f, -forward.x);
    float h = Input.GetAxis("Horizontal);
    float v = Input.GetAsxis("Vertical);
    Vector3 movement = (v * forward + h * right);
    movement *= MoveSpeed;

    playerlogic.Move(movement);
     

 */
