using System.Collections;
using System.Collections.Generic;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using UnityEngine;
using UnityStandardAssets;
using UnityStandardAssets.Characters.FirstPerson;
using UnityStandardAssets.CrossPlatformInput;

public class Game_Manager : MonoBehaviour
{
    static public Game_Manager instance { get { return s_Instance; } }
    static protected Game_Manager s_Instance;

    public RRState[] states;   

    public Text scoreText;
    public Text winText;
    public Text enterText;

    public Text levelNumText;

    public GameObject fps;

    static private int currentLevel = 1;
    static private int score = 0; 
    static private bool hasWon;    

    private FirstPersonController myController;

    private float ScoreDelta = 0;
    private float timeDelay = 0.0f;

    private string  m_currentLevel = "1";

    private bool hasDelayed = false;

    public float m_ScoreMultiplier = 0.5f;

    void Awake()
    {
        s_Instance = this;

        if(fps != null)
        {
            myController = fps.GetComponent<FirstPersonController>();
        }       
    }

    // Start is called before the first frame update
    void Start()
    {       
        //s_Instance = this;
        hasWon = false;      

        if(scoreText != null)
        {
            scoreText.text = "" + score;  
        }

        if (levelNumText != null)
        {
            levelNumText.text = "" + currentLevel;
        }
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            QuitGame();
        }

        if (Input.GetAxis("Submit") == 1 && hasWon) {
		    hasWon = false;
            winText.enabled = false;
            enterText.enabled = false;
            score = 0;
            SwitchState("TitleScreen");
		}        

        if(hasDelayed && !hasWon){
            if(myController != null)
            {
                ScoreDelta = ScoreDelta + Time.deltaTime * myController.displaySpeed * m_ScoreMultiplier;

                if (ScoreDelta >= 1.0f)
                {
                    score += 1;
                    if (scoreText != null){
                        scoreText.text = "" + score;
                    }
                    CheckCoinAdvance();
                    ScoreDelta = 0; 
                }
            }
        }
        else
        {
            timeDelay += Time.deltaTime;
            if (timeDelay >= 1.0f)
            {
                hasDelayed = true;
                timeDelay = 0.0f;
            }
        }        
    }

    public void QuitGame()
    {
        #if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
        #endif
        Application.Quit();
    }
    
    public bool returnHasWon()
    {
        return hasWon;
    }

    public void PickupCoin() {
        score += 100;
        if (scoreText != null)
        {
            scoreText.text = "" + score;
        }
        CheckCoinAdvance();
	}

    public void PickupGem() 
    {
        score += 500;
        if (scoreText != null)
        {
            scoreText.text = "" + score;
        }
        CheckCoinAdvance();
	}

    private void CheckCoinAdvance()
    {
        if (score >= 25000 && currentLevel == 5)
        {
            hasWon = true;
            myController.SetCanUpdate(false);
            winText.enabled = true;
            enterText.enabled = true;
        }
        else if (score >= 16000 && currentLevel == 4)
        {
            setLevel(5);
            SwitchState("Level5");
        }
        else if (score >= 10000 && currentLevel == 3)
        {
            setLevel(4);
            SwitchState("Level4");
        }   
        else if (score >= 5000 && currentLevel == 2)
        {
            setLevel(3);           
            SwitchState("Level3");
        }   
        else if (score >= 2000 && currentLevel == 1)
        {
            setLevel(2);           
            SwitchState("Level2");
        }        
    }

    public void SwitchState(string scene)
    {
        myController.m_bCanUpdate = false;
        m_currentLevel = scene;
        hasDelayed = false;
        timeDelay = 0.0f;
        Invoke("LoadNextLevel", 1.0f);
    }

    private void LoadNextLevel()
    {
        SceneManager.LoadScene(m_currentLevel);
    }

    private void setLevel(int level)
    {
        currentLevel = level;
        if (levelNumText != null)
        {
            levelNumText.text = "" + currentLevel;
        }
    } 

    public void resetLevel()
    {
        currentLevel = 1;
        score = 0;
    }
}

public abstract class RRState : MonoBehaviour
{
    [HideInInspector]
    public Game_Manager manager;

    public abstract void Enter(RRState from);
    public abstract void Exit(RRState to);

    public abstract string GetName();
}
