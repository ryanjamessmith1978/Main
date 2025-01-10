using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class SceneSetup : MonoBehaviour
{
    public GameObject prefab;
	public int numEnemies = 20;
	public Text p1, p2, p3, p4;

    void OnLevelWasLoaded(int level)
    {
        if (level == 1)
        {
			for (int i = 0; i <= numEnemies; i++)
            {
                Instantiate(prefab, Manager.Instance().GetRandomPoint(), Quaternion.identity);
            }
        } 
		p1.text = Manager.Instance ().playOne.ToString ();
		p2.text = Manager.Instance ().playTwo.ToString ();
		p3.text = Manager.Instance ().playThree.ToString ();
		p4.text = Manager.Instance ().playFour.ToString ();
    }
}