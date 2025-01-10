using UnityEngine;
using System.Collections;

public class Archer : Unit {

    private Animator anim;
    private bool specialUsed = false;
    public ParticleSystem smokeBombPart;
    public GameObject smokebomb;

	override public void Start () {
		base.Start ();
        anim = GetComponent<Animator>();

		unitName = "Archer";
		print (unitName + " spawned at " + GetCoords());
	}
	
	override public void ActivateSpecial() 
    {
        if (!specialUsed)
        {
            specialUsed = true;
            specialActivated = true;
            // World.Instance().CheckOccupy(World.Instance().selectedTile.occupant, World.Instance().selectedTile.coords);
            
            smokeBombPart.Play();
            smokebomb.AddComponent<Rigidbody>();
            Rigidbody sb = smokebomb.GetComponent<Rigidbody>();
            sb.transform.Translate(new Vector3(1f, -.45f, 1f), Space.World);
            sb.freezeRotation = true;
            anim.SetBool("isSmokeBomb", true);
            smokebomb.transform.parent = null;
            print("smokeBomb barrage!");
        }
    }
}
