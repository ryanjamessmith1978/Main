using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameController : MonoBehaviour {

    public float playerHealth;
    public GameObject healthBar;
    public Text playerHealthText;
    public Button pause;
    public bool isPaused;
    public GameObject pausePanel;

    public Text playerScoreUI;
    public Text remainingLivesText;
    public Text numberOfLives;
    public Text GAMEOVER;
    public Text youWin;
    public AudioSource theDoctor;
    public AudioClip backMusic;
    public PlayerHealth playerHealthScript;
    public int playerLives;

    private static PlayerController pc;
    private static GameController instance = null;
    private static int score;
   

    // Use this for initialization
    void Awake()
    {
        if (instance != null)
        {
            
            
            theDoctor = GetComponent<AudioSource>();
            //theDoctor.Play();
            playerScoreUI.text = "Score: " + score.ToString();
            remainingLivesText.text = "Remaining Lives: ";
            numberOfLives.text = playerLives.ToString();
            DestroyImmediate(gameObject);
            return;
        }


        playerHealthScript = GetComponent<PlayerHealth>();
        theDoctor = GetComponent<AudioSource>();
        theDoctor.Play();
        youWin.text = null;
        GAMEOVER.text = null;
        pc = GetComponent<PlayerController>();
        playerLives = 3;
        instance = this;
        DontDestroyOnLoad(gameObject);
    }

    public static GameController Instance()
    {
        return instance;
    }

    

    public void AddScore()
    {
        score += 100;
        playerScoreUI.text = "Score: " + score.ToString();
        print("Score: " + score);

        if (score == 2500)
        {
            SceneManager.LoadScene("Level3");
        }

        if (score == 1500)
        {
            SceneManager.LoadScene("Level2");
        }
             
    }

    public void lifeLoss()
    {
        pc = GetComponent<PlayerController>();
        playerLives--;
        remainingLivesText.text = "Remaining Lives: ";
        numberOfLives.text = playerLives.ToString();
        

        if (playerLives == 0)
        {
            GameOver();
        }
              

    }

    public void YouWin()
    {
        youWin.text = "You Win!";
    }

    public void GameOver()
    {
        GAMEOVER.text = "GAME OVER";
        Time.timeScale = 0;
        pausePanel.SetActive(true);
        pause.gameObject.SetActive(true);
        isPaused = true;
    }

    public void LoadMainMenu()
    {
        SceneManager.LoadScene("TitleScreen");
        GAMEOVER.text = "";
        Time.timeScale = 1;
        pausePanel.SetActive(false);
        pause.gameObject.SetActive(false);
        isPaused = false;

    }
}
