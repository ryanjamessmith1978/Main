// *** PlayerLogic Class ***
// This class is for character logic.  Inputs might change but the movement/jumping will remain the same.
// by Ryan J Smith

using UnityEngine;
using System.Collections;

public class PlayerLogic : MonoBehaviour {

    // Each character will need a Rigidbody and spawn point.  
    // Jump power could be moved to other specific inputs, but keeping it consistent makes sense for now
    public Rigidbody rb;   
    public float jumpPower = 10;
    public Transform spawnPoint;
   
    // Use this for initialization
    void Start()
    {   
        // if rb isn't added via Inspector, the code itself will add it
        if (rb == null)
        {
            rb = GetComponent<Rigidbody>();
        }

        //obj = GameObject.Find("OtherObj");

        // prints out the joystick names to the console
        foreach(string name in Input.GetJoystickNames())
        {
            Debug.Log(name);
        }
    }

    // Jump function - adds vertical movement via the rigidbody physics systems
    public void Jump()
    {   
        rb.AddForce(jumpPower * new Vector3(0, 1f, 0), ForceMode.Impulse);       
    }

    // Move function - adds movement via the rigidbody physics systems
    public void Move(Vector3 movement)
    {           
        rb.AddForce(movement);
    }

    // Returns the spawn location of the player
    public Transform ReturnSpawnLocation()
    {
        return spawnPoint;
    }

    void OnCollisionEnter (Collision other)
    {
        if(other.gameObject.CompareTag("Player"))
        {
            Debug.Log("Hit Player");
            rb.AddExplosionForce(jumpPower*35, transform.position, 2);
        }
    }

    void OnTriggerEnter (Collider other)
    {
        if(other.gameObject.CompareTag("DeathVolume"))
        {
            gameObject.SetActive(false);
        }
    }
}
