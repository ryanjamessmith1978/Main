// *** Boat Physics ***
// Boat Physics is the main class that gives the boat buoyancy in water
// Boat Physics also adds air resistant to boat
// It creates two invisible meshes based on the modify boat class and assigns it to two empty game objects in the editor.  The forces act on these meshes
// Created by Ryan J Smith

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class BoatPhysics : MonoBehaviour {

    // Assigned in the editor to figure out where forces are applied
    public GameObject boatMeshObj;
    public GameObject aboveWaterObj;
    public GameObject underWaterObj;
    public Vector3 centerOfMass;

    // Script that does whats needed with the boat mesh.
    private ModifyBoatMesh modifyBoatMesh;
    private Mesh underWaterMesh;
    private Mesh aboveWaterMesh;

    // Boat's RigidBody
    private Rigidbody boatRB;

    //The density of the water the boat is traveling in
    private float rhoWater = BoatPhysicsMath.RHO_OCEAN_WATER;
    private float rhoAir = BoatPhysicsMath.RHO_AIR;

    void Awake()
    {
        // Gets rigid body immediately
        boatRB = this.GetComponent<Rigidbody>();
    }


    // Use this for initialization
    void Start ()
    {
        // Init the script that will modify the boat mesh
        modifyBoatMesh = new ModifyBoatMesh(boatMeshObj, underWaterObj, aboveWaterObj, boatRB);

        //Meshes that are below and above the water
        underWaterMesh = underWaterObj.GetComponent<MeshFilter>().mesh;
        aboveWaterMesh = aboveWaterObj.GetComponent<MeshFilter>().mesh;
    }
	
	// Update is called once per frame
	void Update ()
    {
        //Generate the under water mesh
        modifyBoatMesh.GenerateUnderwaterMesh();

        //Display the under water mesh
        modifyBoatMesh.DisplayMesh(underWaterMesh, "UnderWater Mesh", modifyBoatMesh.underWaterTriangleData);
    }

    // Physics updates
    void FixedUpdate()
    {
        //Change the center of mass - experimental - move to Start() later
        boatRB.centerOfMass = centerOfMass;

        //Add forces to the part of the boat that's below the water
        if (modifyBoatMesh.underWaterTriangleData.Count > 0)
        {
            AddUnderWaterForces();
        }

        //Add forces to the part of the boat that's above the water
        if (modifyBoatMesh.aboveWaterTriangleData.Count > 0)
        {
            AddAboveWaterForces();
        }
    }

    // Add forces to the underwater boat
    void AddUnderWaterForces()
    {
        float Cf = BoatPhysicsMath.ResistanceCoefficient(
            rhoWater,
            boatRB.velocity.magnitude,
            modifyBoatMesh.CalculateUnderWaterLength());

        //To calculate the slamming force we need the velocity at each of the original triangles
        List<SlammingForceData> slammingForceData = modifyBoatMesh.slammingForceData;

        CalculateSlammingVelocities(slammingForceData);

        //Need this data for slamming forces
        float boatArea = modifyBoatMesh.boatArea;
        float boatMass = 1000f; //Replace this line with your boat's total mass

        //To connect the submerged triangles with the original triangles
        List<int> indexOfOriginalTriangle = modifyBoatMesh.indexOfOriginalTriangle;

        //Get all triangles
        List<TriangleData> underWaterTriangleData = modifyBoatMesh.underWaterTriangleData;

        for (int i = 0; i < underWaterTriangleData.Count; i++)
        {
            TriangleData triangleData = underWaterTriangleData[i];


            //Calculate the forces
            Vector3 forceToAdd = Vector3.zero;

            //Force 1 - The hydrostatic force (buoyancy)
            forceToAdd += BoatPhysicsMath.BuoyancyForce(rhoWater, triangleData);

            //Force 2 - Viscous Water Resistance
            forceToAdd += BoatPhysicsMath.ViscousWaterResistanceForce(rhoWater, triangleData, Cf);

            //Force 3 - Pressure drag
            forceToAdd += BoatPhysicsMath.PressureDragForce(triangleData);

            //Force 4 - Slamming force
            //Which of the original triangles is this triangle a part of
            int originalTriangleIndex = indexOfOriginalTriangle[i];

            SlammingForceData slammingData = slammingForceData[originalTriangleIndex];

            forceToAdd += BoatPhysicsMath.SlammingForce(slammingData, triangleData, boatArea, boatMass);


            //Add the forces to the boat
            boatRB.AddForceAtPosition(forceToAdd, triangleData.center);
        }
    }

    // Buoyancy force that makes the boat able to float/bounce
    private Vector3 BuoyancyForce(float rho, TriangleData triangleData)
    {
        Vector3 buoyancyForce = rho * Physics.gravity.y * triangleData.distanceToSurface * 
            triangleData.area * triangleData.normal;

        buoyancyForce.x = 0f;
        buoyancyForce.z = 0f;

        return buoyancyForce;
    }
    //Add all forces that act on the squares above the water
    void AddAboveWaterForces()
    {
        //Get all triangles
        List<TriangleData> aboveWaterTriangleData = modifyBoatMesh.aboveWaterTriangleData;

        //Loop through all triangles
        for (int i = 0; i < aboveWaterTriangleData.Count; i++)
        {
            TriangleData triangleData = aboveWaterTriangleData[i];


            //Calculate the forces
            Vector3 forceToAdd = Vector3.zero;

            //Force 1 - Air resistance 
            //Replace VisbyData.C_r with your boat's drag coefficient
            forceToAdd += BoatPhysicsMath.AirResistanceForce(rhoAir, triangleData, .3f);

            //Add the forces to the boat
            boatRB.AddForceAtPosition(forceToAdd, triangleData.center);


            //Debug

            //The normal
            //Debug.DrawRay(triangleCenter, triangleNormal * 3f, Color.white);

            //The velocity
            //Debug.DrawRay(triangleCenter, triangleVelocityDir * 3f, Color.black);

            if (triangleData.cosTheta > 0f)
            {
                //Debug.DrawRay(triangleCenter, triangleVelocityDir * 3f, Color.black);
            }

            //Air resistance
            //-3 to show it in the opposite direction to see what's going on
            //Debug.DrawRay(triangleCenter, airResistanceForce.normalized * -3f, Color.blue);
        }
    }

    //Calculate the current velocity at the center of each triangle of the original boat mesh
    private void CalculateSlammingVelocities(List<SlammingForceData> slammingForceData)
    {
        for (int i = 0; i < slammingForceData.Count; i++)
        {
            //Set the new velocity to the old velocity
            slammingForceData[i].previousVelocity = slammingForceData[i].velocity;

            //Center of the triangle in world space
            Vector3 center = transform.TransformPoint(slammingForceData[i].triangleCenter);

            //Get the current velocity at the center of the triangle
            slammingForceData[i].velocity = BoatPhysicsMath.GetTriangleVelocity(boatRB, center);
        }
    }

}
