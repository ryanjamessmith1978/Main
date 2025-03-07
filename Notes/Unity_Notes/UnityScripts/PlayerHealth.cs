﻿using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class PlayerHealth : MonoBehaviour {

    public float playerHealth;
    private Text playerHealthText;
    private GameObject healthBar;
    

    public float maxHealth = 1f;
    


    // it'll tick down until it gets to 0, when the timer is less that or equal to 0, something can hit the player
    private float hitTimer = -1f;
    
    

	// Use this for initialization
	void Awake () 
    {
        playerHealth = GameController.Instance().playerHealth;
        playerHealthText = GameController.Instance().playerHealthText;
        healthBar = GameController.Instance().healthBar;
        // In start point to the game controller script to update the player health vairables
        hitTimer = 1;
        //playerHealth = 1f;
        UpdateHUD();
	}
	
	// Update is called once per frame
	void Update () {

        if (hitTimer > 0f)
            hitTimer -= Time.deltaTime;

      	}

    public void Hit(float damage)
    {
        if (hitTimer > 0f)
        {
            return;
            Debug.Log("hitTimer");
        }

        playerHealth -= damage;

        if (playerHealth < 0)
        {
            GameController.Instance().lifeLoss();

            playerHealth = 0;

            SceneManager.LoadScene("Level1");

            ResetHealth();
        }

        hitTimer = 1f;
        UpdateHUD();
    }
  

    public void UpdateHUD()
    {
        playerHealthText.text = "Player Health: " + playerHealth;
        healthBar.transform.localScale = new Vector3(playerHealth, 1f, 1f);
    }

    public void ResetHealth()
    {
        playerHealth = maxHealth;
    }
}
