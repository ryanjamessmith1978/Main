using UnityEngine;
using System.Collections;

public class GhostTele2 : MonoBehaviour {
	
	public Transform[] waypoints;
	Transform waypoint;
	public float tpcount;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		tpcount -= Time.deltaTime *  (Random.Range(1F, 5.0F));
		if (tpcount <= 0)
		{
			RandomGen();
		}
	}
	void RandomGen()
	{
		
		waypoint = waypoints[Random.Range(0, waypoints.Length)];
		this.transform.position = waypoint.position;
		tpcount = 3;
	}
	
}
