using UnityEngine;
using System.Collections;

public class HoldingTrigger : MonoBehaviour {

    private BackandForthPlatform platform;

	void Start () {
        platform = transform.parent.gameObject.GetComponent<BackandForthPlatform>();

	}
	
    void OnTriggerEnter(Collider other)
    {
        platform.AddHeldObject(other.gameObject);
    }

    void onTriggerExit(Collider other)
    {
        platform.removeHeldObject(other.gameObject);
    }
	

}
