using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class GhostMove : MonoBehaviour {

    public bool gameOver = false;
    public int pacLives = 3;

    public AudioClip death;
    public GameObject pac3;
    public GameObject pac2;
    public GameObject pac1;
    public Transform[] waypoints;
    int cur = 0;


    public float speed = 0.3f;
	// Use this for initialization
    void FixedUpdate()
    {
        // Waypoint not reached yet? then move closer
        if (transform.position != waypoints[cur].position)
        {
            Vector2 p = Vector2.MoveTowards(transform.position,
                                            waypoints[cur].position,
                                            speed);
            GetComponent<Rigidbody2D>().MovePosition(p);
        }
        // Waypoint reached, select next one
        else cur = (cur + 1) % waypoints.Length;
    }

       // Update is called once per frame
    void Update () {
	
	}


}
