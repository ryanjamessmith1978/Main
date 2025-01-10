// *** Camera Controller ***
// Prototype 1 - Not used in final simulation, please ignore
// by Ryan J Smith

using UnityEngine;
using System.Collections;

// CameraController class begin
public class CameraController : MonoBehaviour {

    // player transform target
    public Transform target;
    // The offset difference between where camera is located in relation to player in viewport
    private Vector3 offset;
    // smooth rotation
    public float smoothing = 3f;

    void Start()
    {
        offset = transform.position - target.transform.position;
    }

    // Failed attempt at adding a smooth rotate follow for the camera
    void LateUpdate()
    {
       //transform.position = player.transform.position + player.transform.rotation * (Vector3.back * offset.magnitude)+ new Vector3(0f, offset.y, 0f);
	   //transform.rotation = player.transform.rotation;
        Vector3 targetCamPos = target.position + target.transform.position + target.transform.rotation * (Vector3.back * offset.magnitude) + new Vector3(0f, 10f, 0f);
        transform.rotation = target.transform.rotation;

        // Smoothly interpolate between the camera's current 
        // position and it's target position.
        transform.position = Vector3.Lerp(transform.position, targetCamPos, smoothing * Time.deltaTime);

    }
}

