using UnityEngine;
using System.Collections;
using System.Collections.Generic;

// base class for all player characters
public class Unit : MonoBehaviour {

    // keeps track of current tile for which any specific player character is standing on
	public Tile currentTile;

    // public variables for each player character
    private Animator anim;
	public string unitName = "Unit";
	public int hp = 100;
    public int special = 1;
    public int gold = 0;
	public int moveStat = 3;
    public float levelDamageBoost = 0f;
    public float totalDamage = 0;
    public float xp = 0;
    public int unitLevel = 1;
    public AudioSource purchaseSound;
    public AudioSource slice;
    public bool specialActivated = false;
    public GameObject navPointIndicatorPrefab;

    // keeps track of if the player recently purchased a crit bonus attack
    private bool critActive = false;
	// keeps track of the previous Vector3 position of player 
    private Vector3 lastPosition;
    // changes the velocity of the movement for the player from tile to tile, currently disabled
	private float interpolationParam = 0.0f;

    // list of Point structs that holds the value for each x,y coordinate that the player travels
	private List<Point> navPoints = new List<Point>();
    // 	list of prefab gameobject (spheres) that visible show the nav points
	private List<GameObject> navPointIndicators = new List<GameObject>();

	// Use this for initialization
	virtual public void Start () {

        // stores animator component of the base unit class into the anim variable
        anim = GetComponent<Animator>();
        // sets the initial current tile for which the unit is standing on
		currentTile = World.Instance ().GetTileFromPosition (transform.position);
		// sets the move actions of this instanced player character to this unit, and the point (x,y) coordinates of this units coordinates 
        World.Instance ().WarpUnit (this, GetCoords ());
        // sets the initial last position to the current transform
		lastPosition = transform.position;

	}

    // Destroy the Navigation indicators 
	public void DestroyNavIndicators() {
		foreach(GameObject obj in navPointIndicators) {
			Destroy (obj);
		}
		navPointIndicators.Clear ();
	}

    // Destroy the Navigation indicators when moving onto the tile where the next Nav Point resides
	public void DestroyNextNavIndicator() {
		if (navPointIndicators.Count > 0) {
			Destroy(navPointIndicators[0]);
			navPointIndicators.RemoveAt (0);
		}
	}

    // creates a new set of Nav points when a path is determined
	public void ResetNavIndicators() {
		DestroyNavIndicators ();

		if (navPoints == null)
			return;
        // for each coordinate point in the A* algorithms list, a prefab of a sphere is spawned to show Navigation path
		foreach (Point p in navPoints) {
			Vector3 pos = World.Instance ().GetPositionFromCoords(p);
			navPointIndicators.Add ((GameObject) Instantiate(navPointIndicatorPrefab, pos, navPointIndicatorPrefab.transform.rotation));
		}
	}

    // returns true if list is not null, and the count is greater than 0
	public bool NavigateTo(Point coords) {
		navPoints = GetComponent<Navigator> ().ComputePath (GetCoords (), coords);
		ResetNavIndicators ();
		return (navPoints != null && navPoints.Count > 0);
	}

    // interpolates player movement, currently disabled
	public void BeginInterpolatedMove (Point coords) {

		lastPosition = transform.position;
		interpolationParam = 0.0f;
	}

    // checks to see if the unit is moving
	public bool IsMoving() {
		return (navPoints != null && navPoints.Count > 0);
	}

	// Update is called once per frame
	void Update () 
    {
        
        // checks to see if player movement is interpolating and list of Navpoints is not null 
        if (interpolationParam <= 1.0f && navPoints != null && navPoints.Count > 0) {
			// Get the first element of navPoints
			//  Use that element as destination
			Vector3 destination = World.Instance ().GetPositionFromCoords (navPoints[0]);
			transform.position = Vector3.Lerp (lastPosition, destination, interpolationParam);
            float interpolationSpeed = 3.0f;
			interpolationParam += interpolationSpeed*Time.deltaTime;

            // If interpolationParam is >= 1.0f, it's time to go to the next navPoint element
            if(interpolationParam >= 1.0f) {
				lastPosition = World.Instance ().GetPositionFromCoords (navPoints[0]);
				navPoints.RemoveAt (0);
				DestroyNextNavIndicator();
				interpolationParam = 0.0f;
				
			}
		}
	}

    // gets the x,y coordinates for the currently selected tile
	public Point GetCoords() {
		if (currentTile == null)
			return new Point (-1, -1);

		return currentTile.coords;
	}
	
    // left click and right click functionality
	public void OnMouseUpAsButton() {
        // left click selects the unit if the tile underneath that unit is clicked
		if (Input.GetMouseButtonUp (0))
			World.Instance ().Select (GetCoords ());
        // once a unit is selected, right clicking a tile sets the destination point for the player, and moves the player to that tile using A*
		if (Input.GetMouseButtonUp (1))
			World.Instance ().MoveTo (GetCoords ());
	}
	
    // place holder for activating special abilities for the derived classes
	virtual public void ActivateSpecial() 
	{

	}
    
    // allows player to buy a one time crit bonus from the on screen GUI store, if the player has the cash to do so 
    virtual public void BuyCriticalDamage()
    {
        if (gold >= 5)
        {
            gold -= 5;
            AudioSource.PlayClipAtPoint(purchaseSound.clip, transform.position);
            critActive = true;
            World.Instance().UpdateUI();
        }
    }

    // allows player to buy a health potion that brings player back to full health if he has the cash
    virtual public void BuyHealth()
    {
        if (gold >= 10)
        {
            gold -= 10;
            AudioSource.PlayClipAtPoint(purchaseSound.clip, transform.position);
            hp = 100;
            World.Instance().UpdateUI();
        }
    }

    // calculates the distance between current tile point coordinates and selected tile's coordinates
		public float GetDistance(Point to)
	{
		Point distance = (to - GetCoords());
		return Mathf.Abs (distance.x) + Mathf.Abs (distance.y); 
    }

    // checks to see if unit is within 1 tile (not diagonally) to see if attack is possible
	public bool CanAttack(Point to)
	{
		bool canAttack = false;

        if (GetDistance(to) <= 1)
        {
            // if attack is possible, the sword swing animation is performed and canAttack boolean is set to true, else it is set to false
            anim.SetBool("isAttacking", true);
            canAttack = true;
            
        }
        else
            
            canAttack = false;

		return canAttack;

	}

    // Attack function determines if the player is allowed to attack, does the player actually hit the target
	public void Attack(Unit unit)
	{
        // sets the attack to 80% chance to hit
		int canAttack = Random.Range (0, 5);

        // if attack rolls true, then a slice sound is made, and the hit function is called
        if (canAttack >= 1)
        {
            AudioSource.PlayClipAtPoint(slice.clip, transform.position);
            Hit(unit);
        }
        else
        {
            totalDamage = -1;
            World.Instance().UpdateUI();
            return;
        }
    }

    // Hit function determines the amount of damage dealt to the player which gets reported to the on screen GUI
	public void Hit(Unit unit)
	{
		// sets the base damage range for any attack regardless of crit bonus or player level bonus        
		float damage = Random.Range (4, 15);
        //  sets the total damage by adding the base damage plus extra damage if the player is higher leveled
        totalDamage = damage + (damage * levelDamageBoost);

        // increases total damage (one time) to 5 times its roll when unit buys a crit bonus from the store
        if (critActive)
            totalDamage = 5 * totalDamage;
        if (specialActivated)
        {
            // activating special increases damage to 100 for a single attack
            special -= 1;
            totalDamage = 100;
        }

        // changes the hp for the opposing unit that was attacked
		unit.hp -= (int)totalDamage;
        // updates the GUI upon hitting an opposing unit
        World.Instance().UpdateUI();
        // sets critActive and specialActivated to false after each hit performed
        critActive = false;
        specialActivated = false;

        // checks to see if enemy's health is less than or equal to 0, and if so, then it gets destroyed.
        isEnemyDead(unit);
    }

    // checks to see if opposing unit that was attacked is dead, and adds 5 gold to victorious unit
    public void isEnemyDead(Unit unit)
    {
        if (unit.hp <= 0)
        {
            gold += 5;
            World.Instance().UpdateUI();
            Destroy(unit.gameObject);
            xp += .4f;

            if (xp >= 1f)
            {
                unitLevel++;
                levelDamageBoost += .25f;
                xp = 0f;
            }
        }

        World.Instance().UpdateUI();
    }

    // Special town tile that allows player to fill his health back up upon entering tile
    public void OnTriggerEnter(Collider other)
    {

        if (other.gameObject.CompareTag("town"))
        {
            //other.gameObject.SetActive(false);
            hp += 10;
            if (hp >= 100)
                hp = 100;
            World.Instance().UpdateUI();

        }
    }

 
}

	/*
	You will be implementing a set of functions which define the combat interface for Unit objects and you will be writing a short description of the combat system you have designed and the interaction with any stats:

	Unit should have these:

 	GetDistance() returns the distance (either manhattan or chessboard) to a target coordinate.
	
	CanAttack() returns whether or not the occupant of the target coordinates can be attacked by this Unit. is there an enemey, is there something in that tile

	Attack() performs the calculations to make a Unit attack another.

	Hit() performs the calculations for a Unit to take damage (and perhaps die). calls from the other unit


	one is setting up the attack, and hit is when you hit the guy, what the affect is of that hit
 * 
 * 
 * // during update
 * // if attack is performed
 * // check if attack is possible
 * 		// if attack would be based on the distance
 * // if it is possible to attack 	
 *   // perform attack
 * 			// if attack hits then call hit
 * 
 * 
 * 
*/




