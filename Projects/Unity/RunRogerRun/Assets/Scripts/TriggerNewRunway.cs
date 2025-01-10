using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TriggerNewRunway : MonoBehaviour
{
    // Start is called before the first frame update
    public GameObject floorPrefab;

    private RunwayGenerator generator;
    void Start()
    {
        GameObject[] gens =  GameObject.FindGameObjectsWithTag("brickSpawner");
        if (gens[0] != null)
        {
            generator = gens[0].GetComponent<RunwayGenerator>();
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    void OnTriggerEnter(Collider other)
    {
        if(generator != null && other.tag == "Player" ){
            generator.spawnNewRunway(transform.position.z + 100.0f);
        }
    }

    void OnTriggerExit(Collider other)
    {
        if (other.tag == "Player")
        {
            Destroy(gameObject);
        }
    }
}
