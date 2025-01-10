using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using UnityStandardAssets.Characters.FirstPerson;

public class GrabPickups : MonoBehaviour {
	
	private AudioSource pickupSoundSource;
	public Text levelText;
	public LevelGenerator generator;

	void Awake() {
		pickupSoundSource = DontDestroy.instance.GetComponents<AudioSource>()[1];
		levelText.text = "Level " + generator.returnLevel();
	}

	void OnControllerColliderHit(ControllerColliderHit hit) {
		if (hit.gameObject.tag == "Pickup") {
			generator.addLevel();
			pickupSoundSource.Play();
			SceneManager.LoadScene("Play");
		}
	}
}
