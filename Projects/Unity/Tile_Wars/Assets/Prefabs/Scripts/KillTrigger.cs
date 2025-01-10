using UnityEngine;
using System.Collections;

public class KillTrigger : MonoBehaviour {

    public bool p1Stun = false;
    public bool p2Stun = false;
    public bool p3Stun = false;
    public bool p4Stun = false;
    
    public float p1Timer = 1.5f;
    public float p2Timer = 1.5f;
    public float p3Timer = 1.5f;
    public float p4Timer = 1.5f;


    void LateUpdate()
    {
        if (p1Timer <= 0)
        {
            p1Stun = false;
            GameObject.Find("Player1").GetComponent<PlayerController>().enabled = true;
            p1Timer = 1.5f;
        }
       
        if (p1Stun)
            p1Timer -= Time.deltaTime;

        if (p2Timer <= 0)
        {
            p2Stun = false;
            GameObject.Find("Player2").GetComponent<PlayerController_2>().enabled = true;
            p2Timer = 1.5f;
        }

        if (p2Stun)
            p2Timer -= Time.deltaTime;

        if (p3Timer <= 0)
        {
            p3Stun = false;
            GameObject.Find("Player3").GetComponent<PlayerController_3>().enabled = true;
            p3Timer = 1.5f;
        }

        if (p3Stun)
            p3Timer -= Time.deltaTime;
        
        if (p4Timer <= 0)
        {
            p4Stun = false;
			GameObject.Find("Player4").GetComponent<PlayerController_4>().enabled = true;
            p4Timer = 1.5f;
        }

        if (p4Stun)
            p4Timer -= Time.deltaTime;
        }

    
    void OnTriggerEnter (Collider other)
    {
        if (other.CompareTag("Sword1"))
        {
            // kill the enemy
            p1Stun = true;
            EnemyDeath toKill = transform.parent.gameObject.GetComponent<EnemyDeath>();

            toKill.KilledAnim();

            GameObject.Find("Player1").GetComponent<PlayerController>().enabled = false;
         
        }

        if (other.CompareTag("Sword2"))
        {
            // kill the enemy
            p2Stun = true;
            EnemyDeath toKill = transform.parent.gameObject.GetComponent<EnemyDeath>();

            toKill.KilledAnim();

            GameObject.Find("Player2").GetComponent<PlayerController_2>().enabled = false;

        }

        if (other.CompareTag("Sword3"))
        {
            // kill the enemy
            p3Stun = true;
            EnemyDeath toKill = transform.parent.gameObject.GetComponent<EnemyDeath>();

            toKill.KilledAnim();

            GameObject.Find("Player3").GetComponent<PlayerController_3>().enabled = false;

        }

        if (other.CompareTag("Sword4"))
        {
            // kill the enemy
            p4Stun = true;
            EnemyDeath toKill = transform.parent.gameObject.GetComponent<EnemyDeath>();

            toKill.KilledAnim();

            GameObject.Find("Player4").GetComponent<PlayerController_4>().enabled = false;

        }
    }

}
