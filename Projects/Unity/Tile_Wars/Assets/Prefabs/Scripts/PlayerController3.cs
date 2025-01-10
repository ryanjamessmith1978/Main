using UnityEngine;
using System.Collections;

public class PlayerController3 : MonoBehaviour {

    private Rigidbody rb;

    private int sprintburst = 1;
    public bool bombUsed = false;

    public float moveSpeed = 100f;
    public float maxSpeed = 100f;
    public float RotateSpeed = 90f;
    private Animator anim;
    public AudioClip slice;
    public Vector3 angularVelocity;
    public Vector3 inertiaVelocity;
    public ParticleSystem smokeBombPart;
    public GameObject smokebomb;




    void Start()
    {
        rb = GetComponent<Rigidbody>();
        anim = GetComponent<Animator>();
        angularVelocity = new Vector3(0.1f, 0.1f, 0.1f);
        inertiaVelocity = new Vector3(0.0f, 0.0f, 0.0f);
    }


    void FixedUpdate()
    {

        // Movement

        float jMoveVert3 = Input.GetAxis("VerticalController3");
        float jMoveHorz3 = Input.GetAxis("HorizontalController3");



        Vector3 jMove3 = new Vector3(jMoveHorz3, 0.0f, jMoveVert3);

        if (Input.GetButton("A3"))
            sprintburst = 3;
        else
            sprintburst = 1;


        // joystick movement
        if (Input.GetAxis("VerticalController3") > 0 || Input.GetAxis("HorizontalController3") > 0 || Input.GetAxis("VerticalController3") < 0 || Input.GetAxis("HorizontalController3") < 0)
            rb.AddForce(jMove3 * moveSpeed * sprintburst);

        // slice
        if (Input.GetButton("X3"))
        {
            anim.SetBool("isSlicing", true);

        }
        else
            anim.SetBool("isSlicing", false);



        // smoke bomb

        if (Input.GetButton("B3"))
        {
            if (!bombUsed)
            {
                smokeBombPart.Play();
                Rigidbody sb = smokebomb.GetComponent<Rigidbody>();
                sb.transform.Translate(new Vector3(-.05f, -.2f, -.05f), Space.World);
                anim.SetBool("throwSmoke", true);
                smokebomb.transform.parent = null;
                bombUsed = true;
            }

        }
        else
            anim.SetBool("throwSmoke", false);


        // rotate
        if (Input.GetAxis("RotateController3") < 0)
            transform.Rotate(-Vector3.up * RotateSpeed * Time.deltaTime, Space.Self);
        else if (Input.GetAxis("RotateController3") > 0)
            transform.Rotate(Vector3.up * RotateSpeed * Time.deltaTime, Space.Self);
        }

    public void OnTriggerEnter(Collider other)
    {

        if (other.gameObject.CompareTag("Sword1") || other.gameObject.CompareTag("Sword2") || other.gameObject.CompareTag("Sword4"))
        {

            PlayerDeath dead = GetComponent<PlayerDeath>();

            dead.DeathAnim();

            GameObject.Find("Player3").GetComponent<PlayerController3>().enabled = false;

        }

    }

}
