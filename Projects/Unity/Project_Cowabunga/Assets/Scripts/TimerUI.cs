// *** TimeUI class ***
// Class that holds the data for the timer on the top of the screen that keeps track of how long player has been in the race
// by Ryan J Smith

using UnityEngine;
using System.Collections;
using UnityEngine.UI;

// TimerUI class beginning
public class TimerUI : MonoBehaviour {

    // Timer text variable that displays text to UI
    public Text Timer;
    // timer variable that stores amount of time since the play button has been hit
    private float time;

	void Start ()
    {
        time = 0f;
        Timer.text = "Time: " + time.ToString("#00");
	}
	
	// Updates the amount of time that has passed since hitting play
	void Update()
    {
         time = time + Time.deltaTime; 
          Timer.text = "Time: " + time.ToString("#00");
    }

    // returns the amount of time in the timer
    public float GetTime()
    {
        return time;
    }
}
