using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityStandardAssets;
using UnityStandardAssets.Characters.FirstPerson;
using UnityStandardAssets.CrossPlatformInput;

public class Obstacle : MonoBehaviour
{
    // Start is called before the first frame update

    public AudioSource audioSource;
    public FirstPersonController myController;

    private bool bIsTriggered = false;

    void Start()
    {
        myController = GameObject.Find("FPSController").GetComponent<FirstPersonController>();
        bIsTriggered = false;
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void OnTriggerEnter(Collider other)
    {
        if(other.tag == "Player" && bIsTriggered == false){
            bIsTriggered = true;
            
            if (audioSource != null)
            {
                audioSource.Play();
            }
            if (myController != null)
            {          
                myController.FallOver();
            }
            Invoke("Freeze", 0.5f);                      
        }
    }

    void Freeze()
    {
        myController.m_bCanUpdate = false;
        Invoke("ChangeScene", 1.5f);  
    }

    void ChangeScene()
    {
        SceneManager.LoadScene("GameOver");
    }
}
