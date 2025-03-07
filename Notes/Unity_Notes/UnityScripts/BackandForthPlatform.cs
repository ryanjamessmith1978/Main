﻿using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class BackandForthPlatform : MonoBehaviour {

    
    // Need to know how fast the platform moves between points

    public float speed = 1f;
    // two points to move between
    // Vector3 only has values, but Transforms have references, you can mess around in editor to get result
    public Transform pointA;
    public Transform pointB;
    // see how close it gets to point A or point B, then it switches the direction
    public float distanceThreshhold = 1f;
    // know which direction I'm going, the state of the platform

    private bool moveToA = true;

    // new list for side to side platform
    private List<GameObject> heldObjects;

    // the rigidbody has a velocity, but you can't neccessarily set if its' kinematic, change the position of the object.
    public Vector3 velocity;


	// Use this for initialization
	void Start () {

        heldObjects = new List<GameObject>();

        StartCoroutine(StartMoving());
	

	}
	// player slides off
    // add more friction and physicality to the platform
    // hold a list of objects that are attached to the platform, and update their position.


	// Update is called once per frame
    void Update()
    {

        // Euler method to make position over time
        transform.position += velocity * Time.deltaTime;

        // check to see if we get to the threshold right before the points
        if (moveToA)
        {
            if ((pointA.position - transform.position).magnitude <= distanceThreshhold)
            {
                moveToA = !moveToA;
            }

        }
        else if ((pointB.position - transform.position).magnitude <= distanceThreshhold)
        {
            moveToA = !moveToA;
        }

        this.GetComponent<Rigidbody>().position += velocity * Time.deltaTime;
        
        foreach(GameObject obj in heldObjects)
        {
            if (obj == null)
            {
                heldObjects.Remove(obj);
                continue;
            }

            obj.GetComponent<Rigidbody>().position += velocity * Time.deltaTime;
        }

    }

    public void AddHeldObject(GameObject obj)
    {
        if (!heldObjects.Contains(obj.transform.root.gameObject))
            heldObjects.Add(obj.transform.root.gameObject);


    }

    public void removeHeldObject(GameObject obj)
    {
        heldObjects.Remove(obj.transform.root.gameObject);
    }
    
    IEnumerator StartMoving()
    {
        while(true)
        {
            // move the platform

            // velocity takes me from one point to the other
            // which point am I moving toward
            // move to from another point to A
            // need to get a unit Vector, 
            // but first you need to find the difference between the two Vectors pointA and pointB
            // to - from
            // velocity not only needs a direction but a speed
            // put code in both scripts Back and forth platform, and ... (in order to get platform to move smoothly)
            // runs the coroutine once every .1 secs

            if (moveToA)
                velocity = (pointA.position - transform.position).normalized * speed;
            else
                velocity = (pointB.position - transform.position).normalized * speed;


            // Stop function here until next time. - pause what you do in this function, and then Unity do what you need to do, Yield to other actions
            // Yield gives up processor time and wait until next frame

            yield return new WaitForSeconds(distanceThreshhold/speed); // temporal precision time

            // distance threshold is a distance.  In unity the measurement is 1 meter = 1 distance unity
            // speed is measured in meters / seconds
            // convert distance threshold to seconds.  multiple by something that is seconds over meters.  
            // Get the inverse of the velocity, yeah me!

        }

    }

}
