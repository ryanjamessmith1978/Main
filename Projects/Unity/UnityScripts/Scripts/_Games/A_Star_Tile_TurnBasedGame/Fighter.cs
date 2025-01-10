using UnityEngine;
using System.Collections;

public class Fighter : Unit {

    private Animator anim;
    private bool specialUsed = false;

	// Use this for initialization
	override public void Start () {
		base.Start ();

        anim = GetComponent<Animator>();
		unitName = "Fighter";
		print (unitName + " spawned at " + GetCoords());
	}
	
	override public void ActivateSpecial() 
    {
        if (!specialUsed)
        {
            specialUsed = true;
            specialActivated = true;
            print("Beefing up!");
            anim.SetBool("isBashing", true);
        }
    }

}
