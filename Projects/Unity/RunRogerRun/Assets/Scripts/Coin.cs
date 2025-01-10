using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityStandardAssets.Characters.FirstPerson;

public class Coin : MonoBehaviour
{       
    public AudioSource ding;

    private bool bIsTriggered = false;
    void Start()
    {}
    
    void Update()
    {}
    
    void OnTriggerEnter(Collider other) {

        if(other.tag == "Player" && bIsTriggered == false)
        {
            bIsTriggered = true;
            if(ding != null)
            {
                ding.Play();
            }
        }

        Invoke("DestroyCoin", 0.5f);
        Game_Manager.instance.PickupCoin();
		
	}

    void DestroyCoin()
    {
        if(gameObject != null)
        {
            Destroy(gameObject);
        }
    }
    
}