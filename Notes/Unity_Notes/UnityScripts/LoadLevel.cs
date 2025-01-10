using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class LoadLevel : MonoBehaviour {

    public string level;
	
	void Start ()
    {
        
	}
	
	// Update is called once per frame
	void Update () {


    }

    public void OnTriggerEnter(Collider other)
    {
        if(other.gameObject.CompareTag("Player"))
        {
            SceneManager.LoadScene(level);
            //Application.LoadLevel("Level1");
        }

    }
}

