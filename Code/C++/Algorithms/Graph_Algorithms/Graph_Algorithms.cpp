// Graph_Algorithms.cpp | https://www.youtube.com/watch?v=tWVWeAqZ0WU
// freeCodeCamp.org | structy.net
// TODO: Build a graph from edges in a function.

#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <cstring>
#include <set>
#include <sstream>

using namespace std;

class Graph
{
public:

    void insertNode(char node, char neighbors)
    {
        myMap[node].push_back(neighbors);
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

    void depthFirstSearch(Graph& g, char source) // traverses different first path depending on which DFS used
    {
        std::stack<char> searchStack;
        searchStack.push(source);

        while (!searchStack.empty())
        {
            auto current = searchStack.top();
            searchStack.pop();
            std::cout << current << std::endl;

            for (auto neighbor : g.myMap[current])
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

    void breadthFirstSearch(Graph& g, char source)
    {
        std::queue<char> myQueue;
        myQueue.push(source);
        while (myQueue.size() > 0)
        {
            auto& el = myQueue.front();
            myQueue.pop();

            if (el != ' ')
                std::cout << el << std::endl;

            for (auto& neighbor : g.myMap[el])
            {
                myQueue.push(neighbor);
            }
        }

        std::cout << "-----" << std::endl;
    }

    bool hasPathDepthFirst(Graph& g, char src, char dst)
    {
        // Recursive depth first

        if (src == dst) return true;

        for (auto& neighbor : g.myMap[src])
        {
            if (hasPathDepthFirst(g, neighbor, dst) == true)
                return true;
        }
        return false;
    }

    bool hasPathBreadthFirst(Graph& g, char src, char dst) // Recursive not available for breadth first.
    {
        std::queue<char> bfQueue;
        bfQueue.push(src);

        while (!(bfQueue.empty()))
        {
            char currentNode = bfQueue.front();
            bfQueue.pop();
            if (currentNode == dst) { return true; }

            for (auto& neighbor : g.myMap[currentNode])
            {
                bfQueue.push(neighbor);
            }
        }

        return false;
    }

    // TODO: finish
    // void undirectedPath(char edges[], char nodeA, char nodeB)

    // TODO: finish
    //Graph& buildGraph(char edges[]) {}   

    bool hasUndirectedPath(Graph& g, char src, char dst)
    {
        if (src == dst)
            return true;

        // check whether node already traversed.
        if (g.visitedSet.find(src) != visitedSet.end())
            return false;

        g.visitedSet.insert(src);

        for (auto& neighbor : g.myMap[src])
        {
            if (hasUndirectedPath(g, neighbor, dst) == true)
                return true;
        }

        return false;
    }

    int connectedComponentCount(Graph& g)
    {
        int count = 0;
        g.visitedSet.clear();

        for (auto& node : g.myMap)
        {
            if (explore(g, node.first) == true)
            {
                count++;
            }
        }

        return count;
    }

    int largestComponentCount(Graph& g)
    {
        for (auto& node : g.myMap)
        {
            if (explore(g, node.first) == true)
            {
                if (g.visitedSet.size() > g.largestCount)
                    g.largestCount = g.visitedSet.size();
                visitedSet.clear();
            }
        }

        return g.largestCount;
    }

    int shortestPath(Graph& g, char src, char dst)
    {
        std::queue<std::pair<char, int>> shortPathQueue;
        //shortPathQueue.push(std::make_pair(src, 0));
        //g.visitedSet.insert(src);

        while (shortPathQueue.size() > 0)
        {
            auto& node = shortPathQueue.front();
            shortPathQueue.pop();
            if (node.first == dst)
                return node.second;

            for (auto& neighbor : g.myMap[node.first])
            {
                if (!(g.visitedSet.find(neighbor) != visitedSet.end()))
                {
                    g.visitedSet.insert(neighbor);
                    shortPathQueue.push(std::make_pair(neighbor, node.second + 1));
                }
            }
        }

        return -1;
    }

    bool explore(Graph& g, char current)
    {
        if (g.visitedSet.find(current) != visitedSet.end())
            return false;

        g.visitedSet.insert(current);

        for (auto& neighbor : g.myMap[current])
        {
            explore(g, neighbor);
        }

        return true;
    }

    int islandCount(char grid[][5], size_t size)
    {
        //std::set<char>* visited = new set<char>();
        std::set<std::string> visited;
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                bool bExplore = exploreIsland(grid, size, i, j, visited);
                if (bExplore)
                    count++;
            }
        }

        return count;
    }

    int minimumIslandSize(char grid[][5], size_t size)
    {
        std::set<std::string> visited;
        int minSize = 1000000;

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++) // adjust j size for a rectangular shape, in case more or less rows than column size.
            {
                int eSize = exploreSize(grid, size, i, j, visited);
                if (eSize > 0 && eSize < minSize)
                    minSize = eSize;
            }
        }

        return minSize;
    }

    bool exploreIsland(char grid[][5], size_t gridSize, int row, int column, std::set<std::string>& visited)
    {
        bool rowInBounds = 0 <= row && row < gridSize; 
        bool colInBounds = 0 <= column && column < gridSize; //sizeof(grid) / sizeof(grid[0]);

        if (!rowInBounds || !colInBounds)
            return false;

        if (grid[row][column] == 'W')
            return false;

        std::stringstream t; // Easier or cleaner way to do this, creating a string of row,column ?
        t << row << "," << column;
        std::string pos = t.str();
        
        if (visited.find(pos) != visited.end())
            return false;

        visited.insert(pos);
        exploreIsland(grid, gridSize, row - 1, column, visited);
        exploreIsland(grid, gridSize, row + 1, column, visited);
        exploreIsland(grid, gridSize, row, column - 1, visited);
        exploreIsland(grid, gridSize, row, column + 1, visited);

        return true;
    }

    int exploreSize(char grid[][5], size_t gridSize, int row, int column, std::set<std::string>& visited)
    {
        bool rowInBounds = 0 <= row && row < gridSize;
        bool colInBounds = 0 <= column && column < gridSize; //sizeof(grid) / sizeof(grid[0]);

        if (!rowInBounds || !colInBounds)
            return 0;

        if (grid[row][column] == 'W')
            return 0;

        std::stringstream t; // Easier or cleaner way to do this, creating a string of row,column ?
        t << row << "," << column;
        std::string pos = t.str();

        if (visited.find(pos) != visited.end())
            return 0;

        visited.insert(pos);

        int islandSize = 1;
        islandSize += exploreSize(grid, gridSize, row - 1, column, visited);
        islandSize += exploreSize(grid, gridSize, row + 1, column, visited);
        islandSize += exploreSize(grid, gridSize, row, column - 1, visited);
        islandSize += exploreSize(grid, gridSize, row, column + 1, visited);

        return islandSize;
    }

private:
    std::unordered_map<char, std::list<char>> myMap;
    std::set<char> visitedSet;
    int largestCount = 0;
};

void Problem1_graphSearchAlgorithms();
void Problem2_hasPathExample();
void Problem3_undirectedEdgeList(); // Adjacency List
void Problem4_connectedComponentCount();// Determine how many islands (components) exist in a graph
void Problem5_largestComponent();
void Problem6_shortestPath(); // Breadth first traversal algorithm for shortest path. // TODO: Fix this.  
void Problem7_islandCount();
void Problem8_minimumIsland(); 

int main()
{   
    // Problem1_graphSearchAlgorithms();
    // Problem2_hasPathExample();
    // Problem3_undirectedEdgeList();
    // Problem4_connectedComponentCount();
    // Problem5_largestComponent();
    // Problem6_shortestPath(); // TODO: Fix
    // Problem7_islandCount();
    Problem8_minimumIsland();

    system("pause");
}

void Problem1_graphSearchAlgorithms()
{
    Graph g;
    g.insertNode('a', 'c'); // Recursive DFS goes a-c path first 
    g.insertNode('a', 'b'); // Regular DFS goes a-b path first, a-b path is above a-c on the stack (added 2nd).
    g.insertNode('b', 'd');
    g.insertNode('c', 'e');
    g.insertNode('d', 'f');
    g.insertNode('e', ' ');
    g.insertNode('f', ' ');
    g.printAdjList();

    g.breadthFirstSearch(g, 'a'); // a, c, b, e, d, f 

    g.depthFirstSearch(g, 'a'); // a, b, d, f, c, e | goes a-b path first.  
    g.depthFirstRecursive(g, 'a'); // a, c, e, b, d, f | goes a-c path first        
}

void Problem2_hasPathExample()
{
    // Problem 2:  Directed - ACYCLIC - No Cycles 
    // Problem 2 Description: Given acyclic in problem description - didn't need to account for infinite loop in this.
    // Take in a source (f) and destination node (k) - return true or false to see if we can travel to destination.
    // During traveersal search, ask each time if we've reached out destination node.
    // { f:[g,i], g:[h], h:[], i:[g,k], j:[i], k:[] }
    // 
    //  Node(f) -> Node(g) -> Node(h)
    //     |(f,i) / (i:g)
    //  Node(i) <- Node(j)
    //     |(i,k)
    //  Node(k) 

    Graph g2;
    g2.insertNode('f', 'g');
    g2.insertNode('f', 'i');
    g2.insertNode('g', 'h');
    g2.insertNode('g', ' ');
    g2.insertNode('i', 'g');
    g2.insertNode('i', 'k');
    g2.insertNode('j', 'i');

    // bool bHasPath = g2.hasPathDepthFirst(g2, 'j', 'k');
    bool bHasPath = g2.hasPathBreadthFirst(g2, 'j', 'k');

    if (bHasPath)
        std::cout << "Has Path\n";
    else
        std::cout << "Does NOT have Path\n";
}

void Problem3_undirectedEdgeList()
{
    // Undirected Graph Problem                                                 //  Node(i) --- Node(j) // infinite cycle
    // Adjacency List - Graph {nodes -> char array of neighbors};               //     |     /
    // edges: [ [i,j],[k,i],[m,k],[k,l],[o,n] ]; (convert edges to graph)       //  Node(k) --- Node(l)
    // graph:{ i:[j, k], j:[i,k], k:[i, m, l, j], m:[k], l:[k], o:[n], n:[o] }  //     |
                                                                                //  Node(m) 
    // mark Nodes as visited as I travel through them.                                                             
    Graph g3;                                                                   //  Node(o) --- Node(n) // 2 islands can be on one graph.
    
    g3.insertNode('i', 'j');
    g3.insertNode('i', 'k');
    g3.insertNode('j', 'i');
    g3.insertNode('j', 'k');
    g3.insertNode('k', 'i');
    g3.insertNode('k', 'm');
    g3.insertNode('k', 'l');
    g3.insertNode('k', 'j');
    g3.insertNode('m', 'k');
    g3.insertNode('l', 'k');
    g3.insertNode('o', 'n');
    g3.insertNode('n', 'o');    
    bool bHasPath = g3.hasUndirectedPath(g3, 'j', 'm');

    if (bHasPath)
        std::cout << "Has Path\n";
    else
        std::cout << "Does NOT have Path\n";
    
    // g3.printAdjList();
}

void Problem4_connectedComponentCount()
{
    Graph g4; // graph: {3:[], 4:[6], 6:[4,5,7,8}, 8:[6], 7:[6], 5:[6], 1:[2], 2:[1]};

    g4.insertNode('3', ' ');                        //   Node(1) --- Node(2) // 3 connected components, 3 islands.
    g4.insertNode('4', '6');                        //
    g4.insertNode('6', '4');                        //               Node(4)
    g4.insertNode('6', '5');                        //                  |
    g4.insertNode('6', '7');                        //   Node(5) --- Node(6) --- Node(8)
    g4.insertNode('6', '8');                        //                  |
    g4.insertNode('8', '6');                        //               Node(7)
    g4.insertNode('7', '6');                        //
    g4.insertNode('5', '6');                        //   Node(3) : Singleton
    g4.insertNode('1', '2');                        //
    g4.insertNode('2', '1');                        //
    
    int num = g4.connectedComponentCount(g4);
    std::cout << num << std::endl;
   
    // Create counting algorithm to figure out how many connected components (islands)?  This pattern can be depth-first or breadth-first
    // Once completing a path fully explored, increment the # of component count by 1.  Iterate over each node.
    
    // Nodes:
    //  1 - Start a depth first traversal at this node. Continue as far as possible.  Mark as visited, no double count. Add a component count.
    //  2 - Each node needs to run it's own traversal for component count.  This node has been visited, thus skip and keep component count same.
    //  3 - Start a new traversal because 3 is not marked as visisted.  Mark as visisted.  Since singleton, traversal done. Add one to component count.
    //  4 - Since 4 has not been visited, start a traversal and mark 4 as visisted.  
    //      Traverse as far as possible, marking all other nodes as visisted (5, 6, 7, 8) and add one to component count.
    //  5 - Visited, skip.
    //  6 - Visited, skip.
    //  7 - Visited, skip.
    //  8 - Visited, skip.  No more iterations, all nodes traversed.  Return component count of 3.

}

void Problem5_largestComponent()
{
    Graph g5;  // ({0:[8,1,5], 1:[0], 5:[0,8], 8:[0,5], 2:[3,4], 3:[2,4], 4:[3,2]}); // largest component is 4 | determine size of each component. 
   
    g5.insertNode('0', '8');                        //               1
    g5.insertNode('0', '1');                        //               |
    g5.insertNode('0', '5');                        //               0 - 8
    g5.insertNode('1', '0');                        //               |  / 
    g5.insertNode('5', '0');                        //               5
    g5.insertNode('5', '8');                        //                  
    g5.insertNode('8', '0');                        //              2 - 3  
    g5.insertNode('8', '5');                        //              |  /
    g5.insertNode('2', '3');                        //              4
    g5.insertNode('2', '4');                        
    g5.insertNode('3', '2');                        
    g5.insertNode('3', '4');
    g5.insertNode('4', '3');
    g5.insertNode('4', '2');

    int num = g5.largestComponentCount(g5);

    std::cout << "Largest Component Size: " << num << std::endl;
}

void Problem6_shortestPath()
{
    // Edges: [w,x], [x,y], [z, y], [z,v], [w, v]
    // Graph: { w:[x, v], x:[w, y], y:[x, z], z:[y, v], v:[z,w] }

    Graph g6;
    g6.insertNode('w', 'x');
    g6.insertNode('w', 'v');                //   Node(x) --- Node(y)
    g6.insertNode('x', 'w');                //    /                \
                                            // Node(w)          Node(z)
    g6.insertNode('x', 'y');                //      \           /
    g6.insertNode('y', 'x');                //         Node(v)
    g6.insertNode('y', 'z');
    g6.insertNode('z', 'y');
    g6.insertNode('z', 'v');
    g6.insertNode('v', 'z');
    g6.insertNode('v', 'w');
     
    int num = g6.shortestPath(g6, 'w', 'v');
    std::cout << "ShortestPath: " << num << std::endl;
}

void Problem7_islandCount()
{
    char gridGraph[][5] = { 
    {'W', 'L', 'W', 'W', 'W'},
    {'W', 'L', 'W', 'W', 'W'},
    {'W', 'W', 'W', 'L', 'W'},
    {'W', 'W', 'L', 'L', 'W'},
    {'L', 'W', 'W', 'L', 'L'},
    {'L', 'L', 'W', 'W', 'W'} };

    Graph g7;
    size_t graphSize = sizeof(gridGraph) / sizeof(gridGraph[0]);

    int count = g7.islandCount(gridGraph, graphSize); // TODO: make it so don't need to hardcode island count grid size
    std::cout << "Island Count: " << count << std::endl;
}

void Problem8_minimumIsland()
{
    char gridGraph[][5] = {
    {'W', 'L', 'W', 'W', 'W'},
    {'W', 'L', 'W', 'W', 'W'},
    {'W', 'W', 'W', 'L', 'W'},
    {'W', 'W', 'L', 'L', 'W'},
    {'L', 'W', 'W', 'L', 'L'},
    {'L', 'L', 'W', 'W', 'W'} };

    Graph g8;
    size_t graphSize = sizeof(gridGraph) / sizeof(gridGraph[0]); 
    int minSize = g8.minimumIslandSize(gridGraph, graphSize);
    std::cout << "Min Island Size: " << minSize << std::endl;
}

// Graph Algorithms NOTES:
// Nodes things - edges are relationships
// Neighbors are other nodes that a node has access to.  
// Neighbors need to have a directed edge to that node to be a neighbor.
// Graphs are typically used with a hashmap (std::unordered_map) to represent an adjacency list.  O(1) lookup.
// Keys are every node in my graph.  For example node 'A' will represent a key value in my graph.
// Values are an array.  Neighbors of 'A' key as an array.
// Even if a node has no neighbors, it should still be entered as a key in the graph with empty neighbor array.
// Cyclic Graph - a cycle is some path through nodes, I can end up where I first started.   INFINITE Cycles.

// Determining Complexity:
// Define n = # nodes, and e = # of edges. 
// Time: O(n^2) | # number of nodes for any particular graph, each node is bilateral.  n-squared edges.
// Space: O(n)

// Depth First Traversal (Stack):
// If multiple traversal paths to start (multiple directional paths), program can decide which way to go, 'A' to 'B', or 'A' to 'C'.
// After 'A' hits a dead end, it starts over and goes to 'C' on second pass,
// repeat traversal is required if 'A' traversal already hit nodes in previous pass.
// We use traversal algorithm to tell you whether or not you can travel between nodes.
// One direction as much as possible before switching directions.

// Breadth First Traversal (Queue):
// Breadth first must hit all neighbors first.  
// All directions evenly.  

// QUESTIONS:
// How do I implement a Hash Table in C++, if there is no std version of a hash table in C++?
// Hash tables can be implemented in C++ using a combination of arrays and linked lists. 
// The basic idea behind a hash table is to use a hash function to map keys to indices in an array, 
// and then use linked lists to handle collisions (when multiple keys map to the same index).
// 
// Are HashMaps and unordered_maps the same?  Yes.  Updated name convention to unordered_map in C++11
// Hash Maps v Hash Tables?  
// HashMap is not synchronized, therefore it's faster and uses less memory than Hashtable. 
// Generally, unsynchronized objects are faster than synchronized ones in a single threaded application.
// How do you choose direction in Graph Traversal with multiple neighbors?

// When I pop something off the stack, do I still have access to the data that entity holds?  Using a stack DS for example.
// What makes this a graph?  It appears I'm just using an unordered_map (hash map) to manipulate all the data?  Wrapper Graph class?
// Instructor talks about time complexity in terms of O(e) and also says it's O(n-squared)... which one is it and why?
// Difference between Component Count example and Island Count Examples?  
// Answer: Adjusting criteria for looking at neighbors, 2d array, neighbors can only be left, right, up, or down.
