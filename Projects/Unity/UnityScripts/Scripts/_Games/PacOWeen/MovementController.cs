using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class MovementController : MonoBehaviour
{
    private int score = 000;
    private int highScore = 1000;

	public float rotationResetSpeed = 1.0f;
	public AudioClip death;
	public int totalLives = 3;
	public int mspacmanLives = 3;
	public GameObject pac3;
	public GameObject pac2;
	public GameObject pac1;
    public float speed = 0.4f;
    public int pointsPerPellet = 10;
    public int pointsPerFruit = 100;
    public Text Player2Score;
    public Text HighScore;
	public Text GameOver;
    Vector2 dest;
	Vector2 startingPosition;
    public AudioClip chomp;
	public GameObject pacman;
	public GameObject mspacman;
	public bool alive = true;


    void Start()
    {

        dest = transform.position;
		startingPosition = transform.position;
		Player2Score.text = "" + score;
		HighScore.text = "" + highScore;
		GameOver.text = "";
		pacman = GameObject.Find ("Pacman");
		mspacman = GameObject.Find ("Mspacman");
		pac3 = GameObject.Find("MsLives3");
		pac2 = GameObject.Find ("MsLives2");
		pac1 = GameObject.Find ("MsLives1");
	}
	
	void FixedUpdate()
    {

		if (alive == true) 
		{
			// Move closer to Destination
			Vector2 p = Vector2.MoveTowards (transform.position, dest, speed);
			GetComponent<Rigidbody2D> ().MovePosition (p);

			// Check for Input if not moving
			if ((Vector2)transform.position == dest) {
				if ((Input.GetAxis ("VerticalController") > 0) && valid (Vector2.up))
					dest = (Vector2)transform.position + Vector2.up;
				if ((Input.GetAxis ("HorizontalController") > 0) && valid (Vector2.right))
					dest = (Vector2)transform.position + Vector2.right;
				if ((Input.GetAxis ("VerticalController") < 0) && valid (-Vector2.up))
					dest = (Vector2)transform.position - Vector2.up;
				if ((Input.GetAxis ("HorizontalController") < 0) && valid (-Vector2.right))
					dest = (Vector2)transform.position - Vector2.right;
			}
			// Animation Parameters
			Vector2 dir = dest - (Vector2)transform.position;
			GetComponent<Animator> ().SetFloat ("DirX", dir.x);
			GetComponent<Animator> ().SetFloat ("DirY", dir.y);
		}
    }

    private void OnTriggerEnter2D(Collider2D other)
    {
        if (other.tag == "pellet")
        {
            score += pointsPerPellet;
            SoundManager.instance.RandomizeSfx(chomp);
            Player2Score.text = "" + score;

            if (score >= highScore)
                highScore = score;
            HighScore.text = "" + highScore;

            other.gameObject.SetActive(false);
        }

		if (other.tag == "blinky" || other.tag == "pinky")
		{
			mspacmanLives--;


			if (mspacmanLives < 1)
			{
				GameOver.text = "GAME OVER";
				pac1.SetActive(false);
				SoundManager.instance.RandomizeSfx(death);
				Destroy(pacman);
				StartCoroutine("Respawn", 5f);
				Invoke("LoadLevel", 5f);

			}
			else if (mspacmanLives < 2)
			{
				pac2.SetActive(false);
			StartCoroutine("Respawn", 3f);
			}
			else 
			{
				pac3.SetActive(false);
				StartCoroutine("Respawn", 3f);
			}

		}

    }

    bool valid(Vector2 dir)
    {
        // Cast Line from 'next to Pac-Man' to 'Pac-Man'
        Vector2 pos = transform.position;
        RaycastHit2D hit = Physics2D.Linecast(pos + dir, pos);
        return (hit.collider == GetComponent<Collider2D>());
    }

	IEnumerator Respawn(float spawnDelay)
	{
		alive = false;
		SoundManager.instance.RandomizeSfx(death);
		
		transform.position = startingPosition;
		dest = startingPosition;
		
		Vector2 a = Vector2.MoveTowards(transform.position, dest, 0);
		GetComponent<Rigidbody2D>().MovePosition(a);
		
		dest = (Vector2)transform.position - Vector2.right;
		Vector2 dir = dest - (Vector2)transform.position;
		GetComponent<Animator> ().SetFloat ("DirX", dir.x);
		GetComponent<Animator> ().SetFloat ("DirY", dir.y);
		
		yield return new WaitForSeconds (spawnDelay);
		alive = true;
	}

	void LoadLevel()
	{
		Application.LoadLevel (Application.loadedLevel);
	}

}