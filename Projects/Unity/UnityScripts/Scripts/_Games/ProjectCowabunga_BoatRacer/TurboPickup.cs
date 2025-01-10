// *** Turbo Pickup class ***
// The turbo pick ups in the level that add turbo to the player turbo meter
// by Ryan J Smith

using UnityEngine;
using System.Collections;

public class TurboPickup : MonoBehaviour {

	
	void Start ()
    {
	
	}
	
	// Update is called once per frame
	void Update ()
    {
        // rotates the Turbo to make it more noticeable (Is Kinematic?) - See, I pay attention
        transform.Rotate(new Vector3(45, 45, 45) * Time.deltaTime);
	}
}
