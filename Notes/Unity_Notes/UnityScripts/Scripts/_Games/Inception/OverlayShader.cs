/*
 * Greg St. Angelo IV
 * GAME JAM 2016
 * 
 * 11.4.2016
 */
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// HUD Overlay functionality
/// </summary>
public class OverlayShader : MonoBehaviour
{
    // Globals
    public Button redButton, blueButton, greenButton, disableButton;
    public GameObject redOverlay, blueOverlay, greenOverlay;

    private int redPress = 0, bluePress = 0, greenPress = 0;
    private bool rgbCombo = false;
    
    /// <summary>
    /// Makes sure all overlays are disabled on start.
    /// </summary>
    void Start()
    {
        // disables
        blueOverlay.SetActive(false);
        greenOverlay.SetActive(false);
        redOverlay.SetActive(false);
    }


    /// <summary>
    /// Updates the state of this OverlayShader
    /// </summary>
    void Update()
    {
        // check for combos
        if (rgbCombo)
        {
            Debug.Log("RGB COMBO!");
            ResetComboValues();
        }
    }

    /// <summary>
    /// Resets the combo conditions
    /// </summary>
    void ResetComboValues()
    {
        rgbCombo = false;

        redPress = 0;
        bluePress = 0;
        greenPress = 0;
    }

    /// <summary>
    /// Deactivates all overlays in the HUD.
    /// </summary>
    public void DisablePressed()
    {
        // disables
        blueOverlay.SetActive(false);
        greenOverlay.SetActive(false);
        redOverlay.SetActive(false);

        ResetComboValues();
    }

    /// <summary>
    /// Switches screen overlay to red.
    /// </summary>
    public void RedPressed()
    {
        // disables
        blueOverlay.SetActive(false);
        greenOverlay.SetActive(false);
        
        // enables
        redOverlay.SetActive(true);

        // check for combo points
        if(redPress == 0 && greenPress == 0 && bluePress == 0)
        {
            redPress++;
        }
    }

    /// <summary>
    /// Switches screen overlay to blue.
    /// </summary>
    public void BluePressed()
    {
        // disables
        redOverlay.SetActive(false);
        greenOverlay.SetActive(false);
        
        // enables
        blueOverlay.SetActive(true);

        // check for combo points
        if (redPress == 1 && greenPress == 1 && bluePress == 0)
        {
            bluePress++;
            rgbCombo = true;
        }
    }

    /// <summary>
    /// Switches screen overlay to green.
    /// </summary>
    public void GreenPressed()
    {
        // disables
        redOverlay.SetActive(false);
        blueOverlay.SetActive(false);

        // enables
        greenOverlay.SetActive(true);

        // check for combo points
        if (redPress == 1 && greenPress == 0 && bluePress == 0)
        {
            greenPress++;
        }
    }
}
