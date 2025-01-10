// *** RotateFloor class ***
// RotatesFloor
// by Ryan J Smith

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class RotateFloor : MonoBehaviour {

    public Transform floorTransform;
    public List<GameObject> heldObjects = null;
    public float moveSpeed = 10f;
    private Rigidbody rb;

    // the rigidbody has a velocity, but you can't necessarily set if its' kinematic, change the position of the object.
    public Vector3 dragPlayerVelocity;

    // Use this for initialization
    void Start ()
    {
        if (floorTransform == null)
        floorTransform = this.transform;
        heldObjects = new List<GameObject>();
        if (rb == null)
        {
            rb = GetComponent<Rigidbody>();
        }
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        // rotates ground
        rb.AddTorque(new Vector3(0, 10 * moveSpeed, 0));

        // makes players stick
        foreach (GameObject obj in heldObjects)
        {
            if (obj == null)
            {
                heldObjects.Remove(obj);
                continue;
            }

            obj.GetComponent<Rigidbody>().position += dragPlayerVelocity * Time.deltaTime;
           // obj.GetComponent<Rigidbody>().AddRelativeTorque(-0.25f * velocity * Time.deltaTime);
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
}
