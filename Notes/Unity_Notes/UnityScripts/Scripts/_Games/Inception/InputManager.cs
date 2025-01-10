/*
 * Greg St. Angelo IV
 * GAME JAM 2016
 * 
 * 11.4.2016
 */
using UnityEngine;

/// <summary>
/// Manages the majority of the game's input.
/// </summary>
[RequireComponent(typeof(OverlayShader))]
public class InputManager : MonoBehaviour
{
    public OverlayShader os;

    // conditionals for allowing lens switching
    public bool redAllow, greenAllow, blueAllow;

    void Awake()
    {
        redAllow = true;
        greenAllow = false;
        blueAllow = false;
    }

	// Update is called once per frame
	void Update ()
    {
        // check for inputs
        if (Input.GetButtonDown("Red") && redAllow)
        {
            Debug.Log("Red pushed.");
            InitRedOverlay();
        }

        if (Input.GetButtonDown("Blue") && blueAllow)
        {
            Debug.Log("Blue pushed.");
            InitBlueOverlay();
        }

        if (Input.GetButtonDown("Green") && greenAllow)
        {
            Debug.Log("Green pushed.");
            InitGreenOverlay();
        }

        if (Input.GetButtonDown("Disable"))
        {
            Debug.Log("Disable pushed.");
            DisableOverlays();
        }
    }

    /// <summary>
    /// Sets up red overlay.
    /// </summary>
    void InitRedOverlay()
    {
        os.RedPressed();
    }

    /// <summary>
    /// Sets up blue overlay.
    /// </summary>
    void InitBlueOverlay()
    {
        os.BluePressed();
    }

    /// <summary>
    /// Sets up green overlay.
    /// </summary>
    void InitGreenOverlay()
    {
        os.GreenPressed();
    }

    /// <summary>
    /// Disables all overlays
    /// </summary>
    void DisableOverlays()
    {
        os.DisablePressed();
    }
}
