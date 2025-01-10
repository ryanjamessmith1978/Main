using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class BackToTitle : MonoBehaviour
{
    // Start is called before the first frame update
    public Game_Manager manager;
    void Start()
    {
        
    }

    // If you quit, returns to title screen
    void Update()
    {
      if (Input.GetAxis("Submit") == 1) {
			  SceneManager.LoadScene("TitleScreen");
		  }
    }
}
