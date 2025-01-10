// *** WaterController class ***
// Modifies the type of waves that are used in the endless ocean class.  Can be modified in the editor
// I modified the tutorial code quite a bit here.  I made it so you can switch the types of waves directly in the editor via an Enum
// by Ryan J Smith

using UnityEngine;
using System.Collections;

// Water Controller class begin
public class WaterController : MonoBehaviour
{
    // creates a static instance of the class.  Attach to an empty object in the scene
    public static WaterController current;

    // variables for the waves
    public bool isMoving;
    public float scale = 0.1f;
    public float speed = 1.0f;
    public float waveDistance = 1f;
    public float noiseStrength = 1f;
    public float noiseWalk = 1f;
    // default wave type assigned, but can easily modified directly in the editor
    public WaveTypes.WaveType Wave = WaveTypes.WaveType.ROLLING;

    // Use this for initialization
    void Start()
    {
        // sets the wave controller instance to this.
        current = this;
    }

    //Get the y coordinate from whatever wave type we are using
    public float GetWaveYPos(Vector3 position, float timeSinceStart)
    {
        if (isMoving)
        {
            return WaveTypes.SinXWave(position, speed, scale, waveDistance, noiseStrength, noiseWalk, timeSinceStart, Wave);
        }
        else
            return 0f;
    }

    //Find the distance from a vertice to water
    
    public float DistanceToWater(Vector3 position, float timeSinceStart)
    {
        float waterHeight = GetWaveYPos(position, timeSinceStart);

        float distanceToWater = position.y - waterHeight;

        return distanceToWater;
    }

}
