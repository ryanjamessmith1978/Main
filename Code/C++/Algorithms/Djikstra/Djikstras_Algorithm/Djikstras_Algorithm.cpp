// Djikstras_Algorithm.cpp | https://www.youtube.com/watch?v=a1Z1GmKzcPs
// Not sure if this works.

#include <iostream>
using namespace std;

#define INF 999

int cost[100][100]; // graph
int dist[100]; // distance metric for all the nodes
int n; // # of vertices
int src; // source node
bool visited[100] = { 0 };
int parent[100];

void init()
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        parent[i] = i;
    }
    dist[src] = 0;
}

int getMin(int dist[], bool visited[]) {
    int key = 0;
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            key = i;
        }
    }
    return key;
}

void display(int dist[], int par[]) {
    for (int i = 0; i < n; i++) {
        int temp = par[i];
        cout << i << " <- ";
        while (temp != -1)
        {
            cout << temp << " <- ";
            temp = par[temp];
        }
        cout << endl;
        cout << "::::Distance = " << dist[i];
        cout << endl;
    }
}

int getNearest()
{
    // Calculates minimum value of distance
    int minvalue = INF;
    int minnode = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dist[i] < minvalue) // see if node is already visited or not
        {
            minvalue = dist[i];
            //visited[i] = true;
            minnode = i;
        }
    }

    return minnode;
}

void dijkstra2()
{
    for (int i = 0; i < n - 1; i++)
    {
        int nearest = getNearest(); // find nearest unvisited node.
        visited[nearest] = true; // mark it as visited.

        // UPDATE distances of all adjacent nodes!
        // For all adjacent nodes, return nodes that are NOT 999
        for (int adj = 0; adj < n; adj++)
        {
            // check if adj of my nearest adjacent node's distance is not INF(999).
            if (cost[nearest][adj] != INF)
            {   
                // if previous distance of adjacent node is NOT already minimum, update the minimum node.
                // if new distance is lesser distance, then update.
                if (dist[adj] > dist[nearest] + cost[nearest][adj])
                {
                    dist[adj] = dist[nearest] + cost[nearest][adj]; // now keep track of parent node.
                    parent[adj] = nearest;
                }
            }
        }
    }
}

void dijkstra(int src) {
    int par[100], dist[100];
    bool visited[100] = { 0 };
    fill(dist, dist + n, INT_MAX);

    dist[src] = 0;
    par[src] = -1;

    for (int g = 0; g < n - 1; g++) {
        int u = getMin(dist, visited);
        visited[u] = true;
        cout << " min = " << u << endl;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && (dist[u] + cost[u][v]) < dist[v] && cost[u][v] != 9999)
            {
                par[v] = u;
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    display(dist, par);
}


int main(void) {
    cout << "Enter number of vertices : ";
    cin >> n; // enter number of vertices.
    cout << "Enter cost matrix : \n";

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];
    }

    int src;
    cout << "\nEnter source : ";  cin >> src;

    //dijkstra(src);
    //init();
    dijkstra(0);
    //display(dist, parent);

    system("pause");
}


//              GRAPH SETUP:
// 
//      N(3) --7-- N(2) --8--- N(1)
//     9/  \14    4/      \2     |  \4
//     /    \     /       N(8)   |    N(0)
// N(4)--10--- N(5)       |6     |8   
//                2 \     |      |   
//                     N(6)--1--N(7)
//
// N=Node    0:N 1:N
// Node(0) |  0   4  999  999   999   999   999   8   999
// Node(1) |  4   0   8   999   999   999   999   8   999
// Node(2) | 999  8   0    7    999    4    999  999   2
// Node(3) | 999 999  7    0     9    14    999  999  999
// Node(4) | 999 999 999   9     0    10    999  999  999
// Node(5) | 999 999  4    14   10     0     2   999  999
// Node(6) | 999 999 999  999   999    2     0    1    6
// Node(7) |  8   11 999  999   999   999    1    0    7
// Node(8) | 999 999  2   999   999   999    6    7    0


// ADDITIONAL DJIKSTRA NOTES
//
//               A* GRAPH Example
//
//           Node(B)----4----Node(D)
//       2 /    |    \          |    \ 2
//     Node(A)  1       2       3   Node(F)
//       4 \    |         \     |    / 2
//           Node(C)---3---Node(E) -/
//
//      Dijkstra Algorithm Steps:
// 
// 1. Set all Nodes to being unvisited.
// 2. Set all distances of the Nodes to NULL. 
// 3. Set origin Node to be current Node.  
// 4. Set distance of current Node to be 0.
// 5.  Set Current Node to visited.
//
// 1. Set all adjacent nodes label's to Current Node label + edge value (e.g. B = 2, C = 4 labels).
// 2. Check which adjacent node label contains lowest value and set current Node to that node (B is current).
// 3. Repeat steps 1 and 2 of iterative steps (Check labels of B's adjacent Nodes). B(C) = 1, B(E) = 2, B(D) = 6.
//      - C becomes current Node, update C's label from 4 to 3 (A,B,C).  
// 4. Update all labels of node accounting for values starting from A to dest Node, update label to shortest distance.
//      - C (A,B,C) = 3, E (A,B,E) = 4, D (A,B,D) = 6
//      - F = Node(E)->F = 4+2 = 6  or  F = Node(D)->F = 6 + 2 = 8. 
//      - Lowest of A->F or 6 (A,B,E,F).    
//
//   PseudoCode
//
//  wrap start and goal in Nodes
//  insert start node into open list
//  loop while open not empty
//      set current to lowest node in open
//      remove current from open
//      store current adjacent nodes in adjacent linked list
//      loop while adjacent not empty
//          set adj to lowest weighted in adjacent linked list
//          wrap adj in Node
//          set distance to current's g value + DistanceBetween current and adj.
//          if adj node's g is zero or distance is less than adj node's g
//              set adj node's g to distance
//              set adj node's parent to current
//
//          if adj is goal
//              return ReconstructPlan(adj's node)
//
//          insert adj's node into open
//          delete adj from adjancent list
//      end loop
//  end loop
// return