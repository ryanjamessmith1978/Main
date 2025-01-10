using UnityEngine;
using System.Collections;

// Derived class 'Mage' created from the base class 'Unit'
public class Mage : Unit {

    // creates animator variable
    private Animator anim;
    // bool that determines if the special ability has been used
    private bool specialUsed = false;

    // overides the Start function to allow the Mage class to run the base class Start function as well as additional tasks specific to the Mage class
	override public void Start () 
    {
        // runs the Start function for the base class, 'unit'
		base.Start ();

        // assigns the Animator component for this class to the anim variable
        anim = GetComponent<Animator>();
		
        // re-assigns the title of the screen GUI from 'unit name' to 'Mage'
		unitName = "Mage";

        
	}
	
    // overrides base class placeholder in order to use this specific derived class's special
	override public void ActivateSpecial() 
    {
        // only allows special to be used once
        if (!specialUsed)
        {
            // sets your special used to true, so that you can only use once
            specialUsed = true;
            
            // plays the special ability animation from the animator component
            anim.SetBool("isMageStaff", true);
        
        }

    }

   
}
