using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class Manager : MonoBehaviour {

    public int WinScore = 3;

    public int playOne = 0, playTwo = 0, playThree = 0, playFour = 0;

    private int numPlayers = 4;

    private static Manager instance;

    public float wanderArea = 20f;

    public bool pOne = true, pTwo = true, pThree = true, pFour = true;

    private int numAlive = 4;

    void Awake()
    {
        if (instance != null)
        {
            DestroyImmediate(gameObject);
            return;
        }
        instance = this;
        Random.seed = Random.Range(0,50);
        DontDestroyOnLoad(this);
        InvokeRepeating("DestroyEveryTen", 10f, 10f);
    }

    public static Manager Instance()
    {
        return instance;
    }

    public Vector3 GetRandomPoint()
    {
        return new Vector3(Random.Range(-1 * wanderArea, wanderArea), 0, Random.Range(-1 * wanderArea, wanderArea));
    }

    public float GetRandomNum(float floor, float ceiling)
    {
        return Random.Range(floor, ceiling);
    }

    public void CheckNumPlayers(int CalledBy)
    {
        numPlayers -= 1;
        if (numPlayers == 1)
            IncrementScore(CalledBy);
    }

    void IncrementScore(int Player)
    {
        switch (Player)
        {
            case 1:
                playOne += 1;
                CheckWin(playOne);
                break;
            case 2:
                playTwo += 1;
                CheckWin(playTwo);
                break;
            case 3:
                playThree += 1;
                CheckWin(playThree);
                break;
            case 4:
                playFour += 1;
                CheckWin(playFour);
                break;
        }
    }

    void CheckWin(int currentPlayer)
    {
        if (currentPlayer == WinScore)
        {
			SceneManager.LoadScene (2);
        }
        else
        {
            StartCoroutine(WaitToRestart(3));
        }
    }

    void DestroyEveryTen()
    {
        GameObject npc = GameObject.FindWithTag("NPC");
        if (npc != null)
        {
            Destroy(npc);
            Debug.Log("Destroy");
        }
        else
        {
            CancelInvoke();
            Debug.Log("Cancel");
        }
    }

    public void KillPlayer(int playerNum)
    {
        switch (playerNum)
        {
            case 1:
                pOne = false;
                break;
            case 2:
                pTwo = false;
                break;
            case 3:
                pThree = false;
                break;
            case 4:
                pFour = false;
                break;
        }
		CheckForAllDead ();
    }

    IEnumerator WaitToRestart(float waitTime)
    {
        yield return new WaitForSeconds(waitTime);
        ResetManager();
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
    }

    public void ResetManager()
    {
        pOne = true;
        pTwo = true;
        pThree = true;
        pFour = true;
        numAlive = 4;
    }
    public void WinReset()
    {
        ResetManager();
        playOne = 0;
        playTwo = 0;
        playThree = 0;
        playFour = 0;
    }

	private void CheckForAllDead()
	{
		if (!pTwo && !pThree && !pFour)
			IncrementScore(1);
		else if (!pOne && !pThree && !pFour)
			IncrementScore(2);
		else if (!pTwo && !pTwo && !pFour)
			IncrementScore(3);
		else if (!pTwo && !pThree && !pOne)
			IncrementScore(4);
	}
}
