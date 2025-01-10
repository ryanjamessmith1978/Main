using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class NPC : MonoBehaviour
{

    public float walkSpeed = 2f, runSpeed = 5f;

    private NavMeshAgent navAgent;

    void Start()
    {
        navAgent = transform.GetComponent<NavMeshAgent>();
        /*navAgent.speed = walkSpeed;
        navAgent.SetDestination(GetRandPoint());*/
        DecideState();
    }

    private void DecideState()
    {
        int waitTime = Mathf.RoundToInt(GetRandNum(0f, 7f));
        int caseNum = Mathf.RoundToInt(GetRandNum(0f, 2f));
        switch (caseNum)
        {
            //stop, get new point, go to point, walk
            case 0:
                navAgent.speed = walkSpeed;
                StartCoroutine(GoTo(waitTime));
                break;
            //stop, get new point, go to point run
            case 1:
                navAgent.speed = runSpeed;
                StartCoroutine(GoTo(waitTime));
                break;
            //stop, wait for seconds
            case 2:
                StartCoroutine(WaitHere(waitTime));
                break;
                /*
                //Stop, throw smoke
                case 3:
                    StartCoroutine(WaitHere(waitTime));
                    //throw smoke code
                    break;
                //Stop, melee
                case 4:
                    StartCoroutine(WaitHere(waitTime));
                    //melee
                    break;
                    */
        }
    }

    IEnumerator GoTo(int WTime)
    {
        //navAgent.Stop();
        navAgent.SetDestination(GetRandPoint());
        yield return new WaitForSeconds(WTime);
        DecideState();
    }

    IEnumerator WaitHere(int WTime)
    {
        //navAgent.Stop();
        if (WTime > 3)
            WTime -= 3;
        yield return new WaitForSeconds(WTime);
        DecideState();
    }

    private Vector3 GetRandPoint()
    {
        return Manager.Instance().GetRandomPoint();
    }

    private float GetRandNum(float floor, float ceiling)
    {
        return Manager.Instance().GetRandomNum(floor, ceiling);
    }
}
