using UnityEngine;
using System.Collections;

public class PlayerDeath : MonoBehaviour {

    private Animator anim;
    private bool playerIsDead = false;
    public AudioClip death;
	public int playerNum;
      
     void Start()
    {
        anim = GetComponent<Animator>();
    }


    void Update()
    {

    }

    public void DeathAnim()
    {
        // Animate to Death state
        // killed
        
        anim.SetBool("isDead", true);
        AudioSource.PlayClipAtPoint(death, transform.position);
        
        // Destroy the object
        Kill();
    }

        
    public void Kill()
    {
		Manager.Instance().KillPlayer(playerNum);
        playerIsDead = true;

        Destroy(gameObject, 3f);

    }
}
