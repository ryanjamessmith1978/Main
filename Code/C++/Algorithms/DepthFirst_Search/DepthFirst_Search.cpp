// DepthFirst_Search.cpp : https://www.youtube.com/watch?v=tWVWeAqZ0WU

#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
#include <cstring>
#include <set>
#include <stack>
#include <sstream>

using namespace std;

class Graph
{
public:

    void insertNode(char node, char neighbors)
    {
        myMap[node].push_back(neighbors);
    }
    void depthFirstSearch(Graph& g, char source) // traverses different first path depending on which DFS used
    {
        std::stack<char> searchStack;
        searchStack.push(source);

        while (!searchStack.empty())
        {
            auto current = searchStack.top();
            searchStack.pop();
            std::cout << current << std::endl;

            for (auto neighbor : g.myMap[current]) // for each element in the list, associated 
            {
                if (neighbor == ' ') continue;
                searchStack.push(neighbor);
            }
        }

        std::cout << "-----" << std::endl;
    }
    void depthFirstRecursive(Graph& g, char source) // traverses different first path depending on which DFS used
    {
        if (source != ' ') // if array is empty, don't print it out, skip to next recursive call.
            std::cout << source << std::endl;
        for (auto neighbor : g.myMap[source])
        {
            depthFirstRecursive(g, neighbor);
        }
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
    g.insertNode('a', 'b'); // Recursive DFS goes a-c path first 
    g.insertNode('a', 'c'); // Regular DFS goes a-b path first
    g.insertNode('b', 'd');
    g.insertNode('c', 'e');
    g.insertNode('d', 'f');
    g.insertNode('e', ' ');
    g.insertNode('f', ' ');
    g.printAdjList();   

    g.depthFirstSearch(g, 'a'); // a, b, d, f, c, e | goes a-b path first because of stack order.
    g.depthFirstRecursive(g, 'a'); // a, c, e, b, d, f | goes a-c path first      
    // Depth first : LIFO stack(can be recursive) : Adds elements in order, first is 0, second is 1, 
    // but the top of the stack is the last element added(so 1).Adds elements to the top of the stack, 
    // represented by the last index in the stack, and pops from the top of the stack, or the last element in the stack.


    system("pause");
}


// Depth-First Search Notes
// Stack data structure  
// Follows path as long as possible before starting back 
// at starting path node to find next neighbor.
// GOOD for solutions far away from source.
// GOOD for game/puzzle problems
// GOOD for memory.
// NOT good for Shortest Path.
// Time: O(N+E) | Nodes + Edges