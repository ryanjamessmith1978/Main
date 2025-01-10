using UnityEngine;
using System.Collections;

public class HoldingTrigger : MonoBehaviour {

    public RotateFloor platform;

	void Start () {

        if (platform == null)
        platform = GetComponent<RotateFloor>();
	}
	
    void OnCollisionEnter(Collision other)
    {
        Debug.Log("PlayerOn");
        platform.AddHeldObject(other.gameObject);
    }

    void OnCollisionExit(Collision other)
    {
        platform.removeHeldObject(other.gameObject);
    }
	

}
