using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RunwayGenerator : MonoBehaviour
{    
    public GameObject floorPrefab;
    public GameObject[] obstaclePrefab;

    private GameObject ParentObj;

    public GameObject coin;
    public GameObject diamond;

    public int diamondChance = 10;

    public int numOfObstacles = 2;

    public int randomObstacle = 0;

    public  float spawnGap = 10.0f;

    public float spawnZHigh = 2.0f;

    public float spawnZLow = -2.0f;

    void Start()
    {}

    void Update()
    {}

    public void spawnNewRunway(float zPos)
    {        
        ParentObj = Instantiate(floorPrefab, new Vector3(0, 0, zPos), Quaternion.identity);
        spawnObstacles(zPos);
        spawnPickups(zPos);
    }

    private void spawnObstacles(float zPos)
    {
        GameObject childObj;
               
        float randomX = 0;
        float randomY = 1;
        float randomZ = 0;
        float spawnPos = zPos;
       

        for(int i = 0; i < numOfObstacles; i++)
        {           
            randomObstacle = Random.Range(0, 6);
            randomZ = Random.Range(spawnZLow, spawnZHigh);

            if (obstaclePrefab[randomObstacle].name == "BrickWall")
            {
                randomX = Random.Range(-0.65f, 0.65f);
                childObj = Instantiate(obstaclePrefab[randomObstacle], new Vector3(randomX, 0, spawnPos + randomZ), Quaternion.Euler(0, 90, 0));
                childObj.transform.parent = ParentObj.transform;
                spawnPos += spawnGap;
            }
            else if (obstaclePrefab[randomObstacle].name == "RoadWorksBarrierHigh")
            {
                childObj = Instantiate(obstaclePrefab[randomObstacle], new Vector3(0, -0.175f, spawnPos + randomZ), Quaternion.identity);
                childObj.transform.parent = ParentObj.transform;
                spawnPos += spawnGap;
            }
            else if (obstaclePrefab[randomObstacle].name == "RoadWorksBarrier01")
            {
                randomX = Random.Range(-1.4f, 1.2f);                
                childObj = Instantiate(obstaclePrefab[randomObstacle], new Vector3(randomX, 0, spawnPos + randomZ), Quaternion.identity);
                childObj.transform.parent = ParentObj.transform;
                spawnPos += spawnGap;
            }
            else if (obstaclePrefab[randomObstacle].name == "Soccer Ball")
            {
                randomY = Random.Range(1, 6);
                randomX = Random.Range(-1.6f, 1.6f);
                childObj = Instantiate(obstaclePrefab[randomObstacle], new Vector3(randomX, randomY, spawnPos + randomZ),Quaternion.identity);
                childObj.transform.parent = ParentObj.transform;
                spawnPos += spawnGap;
            }
            else if (obstaclePrefab[randomObstacle].name == "StoneWall")
            {
                childObj = Instantiate(obstaclePrefab[randomObstacle], new Vector3(0, 0, spawnPos + randomZ),  Quaternion.Euler(0, 90, 0));
                childObj.transform.parent = ParentObj.transform;
                spawnPos += spawnGap;
            }
            else // obstacle
            {
                randomX = Random.Range(-1.2f, 1.1f);
                randomY = Random.Range(-0.1f, 0.6f);
                childObj = Instantiate(obstaclePrefab[randomObstacle], new Vector3(randomX, randomY, spawnPos + randomZ), Quaternion.identity);
                childObj.transform.parent = ParentObj.transform;
                spawnPos += spawnGap;
            }
        }
    }
    
    private void spawnPickups(float zPos)
    {
        float startingPos = zPos;
        float randomZ = 0.0f;
        float randomX = 0.0f;
        float randomY = 0.0f;

        for(int i = 0; i < 3; i++)
        {
            randomZ = Random.Range(-0.5f, 2.0f) + startingPos;
            randomX = Random.Range(-1.5f, 1.5f);
            randomY = Random.Range(0.5f, 2.0f);            
            GameObject childObj = Instantiate(coin, new Vector3(randomX, randomY, randomZ), Quaternion.identity);
            childObj.transform.parent = ParentObj.transform;
            startingPos += 8.0f;
        }

        int die = Random.Range(1, diamondChance);

        if (die == 1)
        {
            randomZ = Random.Range(0.0f, 25.0f) + startingPos;
            randomX = Random.Range(-2.5f, 2.5f);
            randomY = Random.Range(0.5f, 5.0f); 
            GameObject childObj = Instantiate(diamond, new Vector3(randomX, randomY, randomZ), Quaternion.identity);
            childObj.transform.parent = ParentObj.transform;
        }
    }
}