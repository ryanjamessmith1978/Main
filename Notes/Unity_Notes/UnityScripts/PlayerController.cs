using UnityEngine;
using System.Collections;


public class PlayerController : MonoBehaviour {

    private Rigidbody rb;
    public float speed;
    public float jumpPower;
    //public float moveHorizontal;
    //public float moveVertical;
    Vector3 movement;
    public bool canMove = true;
    bool canJump = false;
    private float rayHeight = 3;
    

   

    void Start()
    {
        rb = GetComponent<Rigidbody>();
       // jumpPower = 1f;
        
        

    }
	
	// Update is called once per frame
	void FixedUpdate ()
    {
        RaycastHit rc;
        
        Vector3 fwd = transform.TransformDirection(Vector3.down);
        Debug.DrawRay(transform.position, fwd * rayHeight, Color.red);
        
        float moveHorizontal = Input.GetAxis("Horizontal");
        float moveVertical = Input.GetAxis("Vertical");



        if (Input.GetButtonDown("Jump") && canJump)
        {
            rb.velocity = new Vector3(0, jumpPower, 0);
            canJump = false;
        }
        
        movement = new Vector3(moveHorizontal, 0f, moveVertical);
        rb.AddForce(movement * speed);
    }

    public void Dead()
    {
        canMove = false;
        movement = new Vector3(0, 0, 0);

    }

   void OnCollisionEnter (Collision other)
    {
        if (other.collider.CompareTag("Ground"))
        {
            canJump = true;
            
        }

        if (other.collider.CompareTag("YouWin"))
        {
            GameController.Instance().YouWin();
        }
    }
 
}
