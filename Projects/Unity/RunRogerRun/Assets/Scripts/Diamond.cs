using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Diamond : MonoBehaviour
{
    // Start is called before the first frame update
    public AudioSource ding;
    private bool bIsTriggered = false;

    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void OnTriggerEnter(Collider other)
    {   
        if(other.tag == "Player" && bIsTriggered == false)
        {
            bIsTriggered = true;
            if(ding != null)
            {
                ding.Play();
            }
        }    
        Invoke("DestroyGem", 1.5f);
        Game_Manager.instance.PickupGem();		
	}

    void DestroyGem()
    {
        if(gameObject != null)
        {
            Destroy(gameObject);
        }
    }        
}
