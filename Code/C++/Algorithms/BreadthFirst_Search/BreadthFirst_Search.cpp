// BreadthFirst_Search.cpp | https://www.youtube.com/watch?v=tWVWeAqZ0WU
// Queue

#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
#include <cstring>
#include <set>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

class Graph
{
public:

    void insertNode(char node, char neighbors)
    {
        myMap[node].push_back(neighbors);
    }

    void breadthFirstSearch(Graph& g, char source) 
    {
        std::queue<char> myQueue;
        myQueue.push(source);
        while (myQueue.size() > 0)
        {
            char currentFront = myQueue.front();
            myQueue.pop();

            if (currentFront != ' ')
                std::cout << currentFront << std::endl;

            for (auto& neighbor : g.myMap[currentFront])
            {
                myQueue.push(neighbor);
            }
        }

        std::cout << "-----" << std::endl;
    }

    void printAdjList()
    {
        for (auto& element : myMap)
        {
            std::cout << "Key: " << element.first << " Neighbors ";
            for (auto& nbr : element.second)
            {
                if (nbr == ' ') continue;
                std::cout << nbr << ", ";
            }
            std::cout << "\n";
        }

        std::cout << "-----" << std::endl;
    }

private:
    std::unordered_map<char, std::list<char>> myMap;
    std::set<char> visitedSet;
    int largestCount = 0;
};

int main()
{
    Graph g;
    g.insertNode('a', 'c'); 
    g.insertNode('a', 'b');
    g.insertNode('b', 'd');
    g.insertNode('c', 'e');
    g.insertNode('d', 'f');
    g.insertNode('e', ' ');
    g.insertNode('f', ' ');
   // g.printAdjList(); // print a key and it's list of neighbors 

    g.breadthFirstSearch(g, 'a'); // a, c, b, e, d, f 

    /*
    Breadth first: FIFO queue.  Remove from the front queue.front() queue.pop 
    and add to the back queue.push_back()
    */
    
    system("pause");
}

// Breadth First Search (BFS) Notes
// 
// Queue data structure  
// Finds all neighbors first
// Used in unweighted graphs
// Better than DFS for searching vertices closer to source.
// GOOD for shortest path
// NOT Good for decision making trees.
// NOT Good for memory
// Time: O(N+E) | Nodes + Edges