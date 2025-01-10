using UnityEngine;
using System.Collections;

public class EnemyAnimation : MonoBehaviour {

    private Animator anim;
    private bool isDead = false;

    void Start()
    {
        anim = GetComponent<Animator>();

    }

    void Update()
    {


    }

    // animate to squish state
    public void Squish()
    {
        anim.SetBool("stomp", true);

        Kill();
    }

    public void Kill()
    {
        isDead = true;
        Destroy(gameObject, 1f);
    }

}
