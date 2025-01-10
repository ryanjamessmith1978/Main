// *** Boat Engine ***
// BoatEngine, BoatPhysics, Debug Physics, Endless Water, ModifyBoatMesh, TriangleData, WaterSquare, and Water Controller are based on tutorials and a GamaSutra article
// GamaSutra Article http://www.gamasutra.com/view/news/237528/Water_interaction_model_for_boats_in_video_games.php
// Habrador Tutorial http://www.habrador.com/tutorials/unity-boat-tutorial/3-buoyancy/
// Ignore this script - I created my own script for player movement called Boat Controller.  This was the reference script from the boat tutorial.   
// Ignore this script - When I tried to delete this script it screwed up my entire solution, and I had load my laptop repository just to get this to work again
// Created By Erik Nordeus 
// Implemented by Ryan J Smith

using UnityEngine;
using System.Collections;

public class BoatEngine : MonoBehaviour
{
    //Drags
    public Transform waterJetTransform;

    //How fast should the engine accelerate?
    public float powerFactor;

    //What's the boat's maximum engine power?
    public float maxPower;

    //The boat's current engine power is public for debugging
    public float currentJetPower;

    private float thrustFromWaterJet = 0f;

    private Rigidbody boatRB;

    private float WaterJetRotation_Y = 0f;

    PlayerController boatController;

    void Start()
    {
        boatRB = GetComponent<Rigidbody>();

        boatController = GetComponent<PlayerController>();
    }


    void Update()
    {
        UserInput();
    }

    void FixedUpdate()
    {
        UpdateWaterJet();
    }

    void UserInput()
    {
        //Forward / reverse
        if (Input.GetKey(KeyCode.W))
        {
            if (boatController.CurrentSpeed < 100f && currentJetPower < maxPower)
            {
                currentJetPower += 1f * powerFactor;
            }
        }
        else
        {
            currentJetPower = 0f;
        }

        //Steer left
        if (Input.GetKey(KeyCode.A))
        {
            WaterJetRotation_Y = waterJetTransform.localEulerAngles.y - 2f;

            if (WaterJetRotation_Y > 30f && WaterJetRotation_Y < 270f)
            {
                WaterJetRotation_Y = 30f;
            }

            Vector3 newRotation = new Vector3(0f, WaterJetRotation_Y, 0f);

            waterJetTransform.localEulerAngles = newRotation;
        }
        //Steer right
        else if (Input.GetKey(KeyCode.D))
        {
            WaterJetRotation_Y = waterJetTransform.localEulerAngles.y + 2f;

            if (WaterJetRotation_Y < 330f && WaterJetRotation_Y > 90f)
            {
                WaterJetRotation_Y = 330f;
            }

            Vector3 newRotation = new Vector3(0f, WaterJetRotation_Y, 0f);

            waterJetTransform.localEulerAngles = newRotation;
        }
    }

    void UpdateWaterJet()
    {
        //Debug.Log(boatController.CurrentSpeed);

        Vector3 forceToAdd = -waterJetTransform.forward * currentJetPower;

        //Only add the force if the engine is below sea level
        float waveYPos = WaterController.current.GetWaveYPos(waterJetTransform.position, Time.time);

        if (waterJetTransform.position.y < waveYPos)
        {
            boatRB.AddForceAtPosition(forceToAdd, waterJetTransform.position);
        }
        else
        {
            boatRB.AddForceAtPosition(Vector3.zero, waterJetTransform.position);
        }
    }
}