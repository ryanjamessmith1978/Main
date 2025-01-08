// BasicGraph_P2.cpp 
// Weighted Graph - Not using an array of lists, but an unordered_map. (sometimes refered to as a hashmap).
// https://www.youtube.com/watch?v=drpdVQq5-mk
// 

#include <iostream>
#include <unordered_map>
using namespace std;

class Graph
{
public:
	
	void addEdge(string x, string y, bool bidirectional, int weight);
	void printAdjList();

private:

	// Adj list of an unordered_map
	unordered_map<std::string, list<pair<std::string, int>>> myWeightedGraph;	
};

int main()
{
	Graph g; // unordered_map: < string-><pair> >

	g.addEdge("A", "B", true, 20);	//			 20				
	g.addEdge("B", "D", true, 30);	//	Node(A)	----- Node(B)	// A -> (B,20), (C,10), (D,50)
	g.addEdge("A", "C", true, 10);	//	   |	\		 |		// B -> (A, 20), (D, 30)
	g.addEdge("C", "D", true, 40);	//	10 |	  \ 50	 |  30  // C -> (A, 10), (D, 40)
	g.addEdge("A", "D", false, 50);	//	   |		\    |      // D -> (A, 50), (B, 30), (C,40)
									//	Node(C)	----- Node(D)
									//			 40	
	// Print List
	g.printAdjList();
   
	system("pause");
}

// Pass in what type of edge as a bool, unidirectional or bidirectional.
void Graph::addEdge(string x, string y, bool bidirectional, int weight)
{
	// Map of x - value - put into the list.
	myWeightedGraph[x].push_back(make_pair(y, weight));

	if (bidirectional) // if bidirectional, x->y and y->x | bidirectional is true, uni is false.
		myWeightedGraph[y].push_back(make_pair(x, weight));
}

void Graph::printAdjList()
{
	for (auto& mapIndex : myWeightedGraph)
	{
		std::string city = mapIndex.first;
		std::list<std::pair<string, int>> nbrs = mapIndex.second;
		std::cout << city << "-> ";

		for (auto nbr : nbrs)
		{
			std::cout << "Destination " << nbr.first << "-Distance: " << nbr.second << ", ";
		}

		std::cout << "\n";
	}
}
// Graph Notes:
// Math Graph terms:
// Graph G is an ordered pair of a set Vertices V and Edges E.  G = (V, E). Mathematical 
// Ordered Pair: (a, b) != (b,a)  if a doesn't equal b.  Pair of mathematical objects.  Order DOES matters.
// Unordered Pair: {a, b} = {b, a}.  Order DOESN't matter.

// Directed edge is an ordered pair (origin, dest) one way.  
// 2 Directed edges are bidirectional connection between ordered pairs. (origin, dest) and (dest, origin)
// Undirected edge is also bidirectional but is represented as {origin, dest} because it's an unordered pair.
// Social network is an Undirected graph.  Friendship is two ways and order doesn't matter.  
// Web pages can be represented as a directed graph.  The relationship isn't mutual.  Co-links between pages not required.
// Web crawling (search engines) use graph traversal for search queries.

// Weighted Graph Notes:
// All connections cannot be treated as equals.
// Intercity road network is an example of a weighted graph (undirected for highways).
// Associate weight or cost for each edge.  
// Unweighted graph is a type of weighted graph where all edges are weighted as 1 (the same).  

// QUESTIONS
// When to use a graph?  When to use a standard graph vs a weighted graph?
// Do weighted maps always use unordered_maps? 
// Any tree is also a graph?  Yes.  Graph is a parent of a tree.  
// Any graph also a tree?  Nope.  tree is child, Graph is parent.
// When you index into a map, is that the same thing as creating a <pair> object and inserting it into the map?
// How to represents an edge?  A pair of two endpoints.
// Hashmap vs. an unordered_map?
