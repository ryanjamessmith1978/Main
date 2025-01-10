// *** CameraSmoothRotate ***
// CameraController script prototype2 - Another fail, please ignore
// C:\Users\RyanJSmith\Desktop\GAM330\GAM330_RJS_Repo\Lab 2\Project_Cowabunga\Assets\Standard Assets\Utility\SmoothFollow.cs - this was the script I used for my camera
// by Ryan J Smith

using UnityEngine;
using System.Collections;

public class CameraSmoothRotate : MonoBehaviour {

    private Vector3 v3Offset;
    private GameObject goFollow;
    private float speed = .1f;

    void Start()
    {
        // attempt to set and rotate the player on a slight delay for the rotation
        goFollow = Camera.main.gameObject;
        v3Offset = transform.position - goFollow.transform.position;
    }

    void LateUpdate()
    {
        // attempt to set and rotate the player on a slight delay for the rotation
        transform.position = goFollow.transform.position + v3Offset;
        transform.rotation = Quaternion.Slerp(transform.rotation, goFollow.transform.rotation, speed * Time.deltaTime);
    }
}
