﻿using UnityEngine;
using System.Collections;

public class DeathVolume : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

    public void OnTriggerEnter (Collider other)
    {
        if(other.CompareTag("Player"))
        {
            GameController.Instance().lifeLoss();
        }

    }
}
