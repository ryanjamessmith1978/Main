using UnityEngine;
using System.Collections;

public class CameraController : MonoBehaviour {

    Vector3 offset;
    //public UnityChanController uc;
    public PlayerController pc;
    

    void Start ()
    {
        offset = transform.position - pc.transform.position;

        
	}
	
	// Update is called once per frame
	void Update ()
    {
        transform.position = pc.transform.position + offset;

	}
}
