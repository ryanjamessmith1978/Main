using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityStandardAssets.Characters.FirstPerson;

public class GameOverTrigger : MonoBehaviour {

	// Use this for initialization
	public LevelGenerator generator;
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	void OnTriggerEnter(Collider other) {

		generator.resetLevel();
		SceneManager.LoadScene("GameOver");
	}

	// 
}
