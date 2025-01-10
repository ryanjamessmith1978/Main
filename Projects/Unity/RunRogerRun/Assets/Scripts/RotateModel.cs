using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RotateModel : MonoBehaviour
{
    // Start is called before the first frame update

    public float rotateSpeed = 0.0f;
    void Start()
    {   
        if (rotateSpeed == 0.0f){
            rotateSpeed = 1.0f;
        }
        
    }

    // Update is called once per frame
    void Update()
    {
        transform.Rotate (Vector3.up*rotateSpeed);
    }
}
