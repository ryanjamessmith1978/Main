﻿using UnityEngine;
using System.Collections;

public class SpawnPlayer : MonoBehaviour {

    public GameObject[] spawnPoints;
    public GameObject player;

	// Use this for initialization
	void Start () 
    {
        PlayerSpawn();
 
	}
	
	public void PlayerSpawn()
    {
        int spawn = Random.Range(0, spawnPoints.Length);

        GameObject.Instantiate(player, spawnPoints[spawn].transform.position, Quaternion.identity);

    }

}
