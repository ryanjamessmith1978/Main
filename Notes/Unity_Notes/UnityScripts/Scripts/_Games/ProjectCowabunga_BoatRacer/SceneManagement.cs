// *** Scene Management class ***
// allows a user to specify loading a level based on a string they type in the editor
// by Ryan J Smith

using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class SceneManagement : MonoBehaviour {

    public string Level_Name;

	void Start ()
    {
	
	}
	
	// Update is called once per frame
	void Update ()
    {
	
	}

    public void LoadLevel(string level)
    {
        SceneManager.LoadScene(level);
    }

}
