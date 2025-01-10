using UnityEngine;
using System.Collections;

public class ObjectGenerator : MonoBehaviour {


    public GameObject toGenerate;
    public float initialDelay = 3f;
    public float delay = 1f;

    void Start () 
    {
        Invoke("Generate", initialDelay);
        // InvokeRepeating("Generate", initialDelay, delay);   
	}
	
	// Update is called once per frame
	void Update () 
    {
        
	}

    void Generate()
    {
        Instantiate(toGenerate, transform.position, transform.rotation);
        Invoke("Generate", delay);
    }
}
