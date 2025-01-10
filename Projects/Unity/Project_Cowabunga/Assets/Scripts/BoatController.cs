// *** Boat Controller ***
// This is the script primarily responsible for player controls & player movement
// by Ryan J Smith

using UnityEngine;
using System.Collections;

// Boat Controller Class Start
public class BoatController : MonoBehaviour {

    // rigid body for player
    private Rigidbody rb;    
    // Move speed multiplier
    public float MoveSpeed;
    // Start Speed
    public float InitialMoveSpeed;
    // Rotate Speed
    public float RotateSpeed;
    // Turbo Meter
    public float TurboMeter;
    // WaterJet Transform (if I want to apply a force to an empty game object in the scene attached to player)
    public GameObject waterJetTransform;
    // Has the player crossed the finish line
    private bool crossedFinish;
    
    // Initial values of Player
    void Start() {

        // Turbo meter resets to full
        TurboMeter = 1f;
        // Move speed is set to the initial speed
        MoveSpeed = InitialMoveSpeed;
        // assigns rigid body
        rb = GetComponent<Rigidbody>();
        // sets crossed finish to false
        crossedFinish = false;
        // sets the GAME Controller singleton's Boat Controller instance to this instance
        GameController.GetInstance.BC = this;
    }
        
    void Update()
    {   
        // resets turbo bool pressed to false each frame
        bool IsTurbo = false;

        // clamps turbo value between 0 and 1
        if (TurboMeter > 1.01f)
            TurboMeter = 1f;

        if (TurboMeter < 0f)
            TurboMeter = 0f;

        // continually refills Turbo meter by a slight amount
        TurboMeter += .01f * Time.deltaTime;

        // checks to see if turbo button is being pressed and if the turbo meter has any juice in it
        if (Input.GetButton("Turbo") && TurboMeter > .01f)
        {
            TurboMeter -= .1f * Time.deltaTime;
            IsTurbo = true;
        }
        else
            IsTurbo = false;  

        // floats based on gas, reverse and rotate that are calculated via the Input Manager
        float gas = Input.GetAxis("Gas");
        float reverse = Input.GetAxis("Break");
        float RotateBoat = Input.GetAxis("Horizontal");
        float moveVertical = Input.GetAxis("Vertical");
        
        // keyboard forward
        Vector3 keyBoardMove = new Vector3(0f, 0f, moveVertical);
        rb.AddRelativeForce(MoveSpeed * keyBoardMove);

        // gas and break trigger movement vectors
        Vector3 movement = MoveSpeed * new Vector3(0f, 0f, gas);
        Vector3 moveBackwards = -0.5f * MoveSpeed * new Vector3(0f, 0f, reverse);
                
        // The amount of force applied depending on if turbo is being pressed
        if (gas > 0f && IsTurbo)
            rb.AddRelativeForce(movement * 3f);
        else if (gas > 0f && !IsTurbo)
            rb.AddRelativeForce(movement);
        // The amount of reverse thrust being applied if holding down the break
        if (reverse > 0f)
            rb.AddForce(moveBackwards);

        // The amount of rotation/torque being applied (thanks for going over this in class)
        rb.AddTorque(new Vector3(0f, RotateBoat * RotateSpeed, 0f));
    }

    // returns the amount of Turbo.  Passed to GameController for UI
    public float GetTurbo()
    {
        return TurboMeter;
    }

    // When overlapping a Turbo or Finish line, stuff happens
    public void OnTriggerEnter(Collider other)
    {
        // when overlapping a turbo, turbo disappears, and player adds more turbo to his meter
        if(other.gameObject.CompareTag("turboPickup"))
        {
            other.gameObject.SetActive(false);
            TurboMeter += .33f;
        }

        // When crossing the finish line, Finish text appears, and the countdown timer to restart the level begins... 7 seconds later the level restarts
        if(other.gameObject.CompareTag("FinishLine"))
        {            
            crossedFinish = true;
            GameController.GetInstance.SetFinish();
            StartCoroutine("DelayTime", 7.0f);                
        }
    }

    // returns if the player has crossed the finish
    public bool HasCrossedFinish()
    {
        return crossedFinish;
    }
    public float GetSpeed()
    {
        return MoveSpeed;
    }

    // Had quite a bit of trouble with this.  I had it on the GameController for the longest time, but realized the refs would be destroyed
    // so I put in on the player instead.  Also I moved the GameController.ResetScene function call to inside this co-routine to work correctly
    IEnumerator DelayTime(float SpawnDelay)
    {
        Debug.Log(Time.time);        
        yield return new WaitForSeconds(SpawnDelay);
        GameController.GetInstance.ResetScene();
        Debug.Log(Time.time);
    }

}
