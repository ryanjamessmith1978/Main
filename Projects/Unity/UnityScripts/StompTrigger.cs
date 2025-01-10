using UnityEngine;
using System.Collections;

public class StompTrigger : MonoBehaviour {



    void OnTriggerEnter(Collider other)
    {
        // Squish the parent of this trigger
        if(other.CompareTag("Stomper"))              
        {
            EnemyAnimation toSquish = transform.parent.gameObject.GetComponent<EnemyAnimation>();
            toSquish.Squish();
        }

    }
    
}
