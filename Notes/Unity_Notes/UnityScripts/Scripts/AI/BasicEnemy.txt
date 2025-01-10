using UnityEngine;
using System.Collections;

public class BasicEnemy : MonoBehaviour {

    private NavMeshAgent agent;
    private bool isEnemyDead;
    public Transform target;
    
    

	// Use this for initialization
	void Start () {

        isEnemyDead = false;
        agent = GetComponent<NavMeshAgent>();

	}
	
	// Update is called once per frame
	void Update ()
    {
        agent.SetDestination(target.position);
	}

    void OnCollisionEnter (Collision other)
    {
        OnCollisionStay(other);
    }

    void OnCollisionStay(Collision other)
    {
        if (isEnemyDead)
            return;

        if (other.gameObject.CompareTag("Player"))
        {
            PlayerHealth ph = other.gameObject.GetComponent<PlayerHealth>();
            ph.Hit(0.1f);
            
        }
    }
}
