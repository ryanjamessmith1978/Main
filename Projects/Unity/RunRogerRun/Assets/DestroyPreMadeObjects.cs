using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DestroyPreMadeObjects : MonoBehaviour
{
    // Start is called before the first frame update

    public GameObject Premades;
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.tag == "Player" && Premades != null)
        {
            Invoke("Dead", 1.5f);       
        }
    }

    void Flash()
    {
        Destroy(Premades);
    }
}
