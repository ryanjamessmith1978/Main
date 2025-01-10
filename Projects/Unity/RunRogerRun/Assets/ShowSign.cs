using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShowSign : MonoBehaviour
{
    // Start is called before the first frame update

    public GameObject Sign;
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.tag == "Player" && Sign != null)
        {
            Sign.SetActive(true);
            Invoke("Flash", 0.5f);       
        }
    }

    void Flash()
    {
        Sign.SetActive(false);
        Invoke("FlashOn", 0.5f);
    }

    void FlashOn()
    {
        Sign.SetActive(true);
        Invoke("FlashOff", 0.25f);
    }
    void FlashOff()
    {
        Sign.SetActive(false);
        Invoke("FlashOn", 0.25f);
    }
}
