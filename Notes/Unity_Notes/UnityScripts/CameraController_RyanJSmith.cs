using UnityEngine;
using System.Collections;

public class CameraController : MonoBehaviour {

	private Vector3 offset;
	public Transform target;
	public GameObject player;
	public float smoothing = 3f; 

	// Use this for initialization
	void Start () 
	
	{
		offset = transform.position - target.position;
	}
	
	// Update is called once per frame
	void LateUpdate () 
	{

		/*transform.position = player.transform.position + player.transform.rotation * (Vector3.back * offset.magnitude)+ new Vector3(0f, offset.y, 0f);
		transform.rotation = player.transform.rotation;
*/
		Vector3 targetCamPos = target.position + target.transform.position + target.transform.rotation * (Vector3.back * offset.magnitude) + new Vector3 (0f, offset.y, 0f);
		transform.rotation = target.transform.rotation;
		
		// Smoothly interpolate between the camera's current 
		// position and it's target position.
		transform.position = Vector3.Lerp (transform.position, 
		                                   targetCamPos,   
		                                   smoothing * Time.deltaTime);

	}
}
