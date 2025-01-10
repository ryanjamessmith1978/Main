// *** WaveType class ***
// Creates Waves based on sine curves
// By Ryan J Smith

using UnityEngine;
using System.Collections;

public class WaveTypes
{

        // Enum for storing the types of waves that can be constructed
        public enum WaveType { STRAIGHT, UP_DOWN, ROLLING, MOVING_SEA};

        //Sinus waves
        public static float SinXWave(
        Vector3 position,
        float speed,
        float scale,
        float waveDistance,
        float noiseStrength,
        float noiseWalk,
        float timeSinceStart,
        WaveType Wave)
    {        

         float x = position.x;
         float y = 0f;
         float z = position.z;

         float waveType = DetermineWaveType(Wave, ref x, ref y, ref z);

         y += Mathf.Sin((timeSinceStart * speed + waveType) / waveDistance) * scale;

         //Add noise to make it more realistic
         y += Mathf.PerlinNoise(x + noiseWalk, y + Mathf.Sin(timeSinceStart * 0.1f)) * noiseStrength;

         return y;
    }

    // Based on Enum assigned in the editor from water controller, this function will change the types of waves constructed at runtime
    // Using only x or z will produce straight waves
    // Using only y will produce an up/down movement
    // x + y + z rolling waves
    // x * z produces a moving sea without rolling waves

    public static float DetermineWaveType(WaveType Wave, ref float x, ref float y, ref float z)
    {
        switch (Wave)
        {
            case WaveType.STRAIGHT:
            {
                    return x;
            }
            break;
            case WaveType.UP_DOWN:
            {
                    return y;
            }
            break;
            case WaveType.ROLLING:
            {
                    return x + y + z;
            }
            break;
            default:
            case WaveType.MOVING_SEA:
            {
                    return x * z;
            }
            break;
        }
    }    
}
