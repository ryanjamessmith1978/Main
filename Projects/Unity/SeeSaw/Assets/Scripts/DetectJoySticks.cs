// *** DetectJoySticks class ***
// Detects Joysticks
// by Ryan J Smith

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class DetectJoySticks : MonoBehaviour {

    public string[] JoystickNames = null;
    public List<int> joystickIndex;

	void Start ()
    {
        // Gets joystick names
        JoystickNames = Input.GetJoystickNames();

        // Print joystick name and index
        int i = 0;
	    foreach(string name in JoystickNames)
        {
            joystickIndex.Add(i);
            Debug.Log(i + ": " + name);
            i++;
        }       
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
