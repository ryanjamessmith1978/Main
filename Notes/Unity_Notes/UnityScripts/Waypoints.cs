﻿using UnityEngine;
using System.Collections;

public class Waypoints : MonoBehaviour {

    public Transform[] waypoints;
    public float speed = 0.3f;
    bool isEnemyDead = false;
    
    int cur = 0;



	
	void FixedUpdate () 
    {
        if (transform.position != waypoints[cur].position)
        {
            Vector3 p = Vector3.MoveTowards(transform.position, waypoints[cur].position, speed);

            GetComponent<Rigidbody>().MovePosition(p);
        }

        else 
            cur = (cur + 1) % waypoints.Length;
	
    }

    void OnCollisionEnter(Collision other)
    {
        OnCollisionStay(other);
    }

    void OnCollisionStay(Collision other)
    {
        if (isEnemyDead)
            return;

        if (other.gameObject.CompareTag("Player"))
        {
            PlayerHealth ph = other.gameObject.GetComponent<PlayerHealth>();
            ph.Hit(0.1f);

        }
    }
}
