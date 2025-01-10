using UnityEngine;
using System.Collections;
using System.Collections.Generic;

[RequireComponent (typeof (NavMeshAgent))]
public class MoveToRandomWaypoint : MonoBehaviour {

    private NavMeshAgent agent;
    public List<Transform> waypoints;

	void Start () {

        agent = GetComponent<NavMeshAgent>();
        if (waypoints.Count > 0)
            agent.SetDestination(waypoints[Random.Range(0, waypoints.Count)].position);
	}
	
	// Update is called once per frame
	void Update () 
    {
        if (agent.remainingDistance < 0.5f)
        {
            if(waypoints.Count > 0)
            agent.SetDestination(waypoints[Random.Range(0, waypoints.Count)].position);
        }
        // agent.SetDestination(target.position);
	}
}
