using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using UnityEngine.UI;



public class WinGame : MonoBehaviour {

	// Use this for initialization
	public Text myCanvas;

	void Start () {

		
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	void OnTriggerEnter(Collider other) {

		myCanvas.enabled = true;

	}
}