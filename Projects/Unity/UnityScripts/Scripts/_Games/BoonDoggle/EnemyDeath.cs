using UnityEngine;
using System.Collections;

public class EnemyDeath : MonoBehaviour {

    private Animator anim;
    private bool isDead = false;
    public AudioClip death;
    
    /*
    public GameObject player1;
    public GameObject player2;
    public GameObject player3;
    public GameObject player4;
    */
	
    void Start () 
    {
        anim = GetComponent<Animator>();
	}
	
	
	void Update () 
    {
	
	}

    public void KilledAnim()
    {
        // Animate to squished state
        // killed
        anim.SetBool("stomp", true);
        AudioSource.PlayClipAtPoint(death, transform.position);
        // Destroy the object

        Kill();
    }

    public void Kill()
    {
        isDead = true;
       
        Destroy(gameObject, 3f);

    }
}
