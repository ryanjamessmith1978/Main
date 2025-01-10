using UnityEngine;
using System.Collections;

public class Collectables : MonoBehaviour {

    public AudioSource collectSound;
	
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

    public void OnTriggerEnter (Collider other)
    {
        if (other.CompareTag("Player"))
        {
            //PlayerController pc = other.GetComponent<PlayerController>();
            //collectSound.Play();
            AudioSource.PlayClipAtPoint(collectSound.clip, transform.position);
            gameObject.SetActive(false);
            // pc.AddScore(1);
            GameController.Instance().AddScore();

        }
    }
}
