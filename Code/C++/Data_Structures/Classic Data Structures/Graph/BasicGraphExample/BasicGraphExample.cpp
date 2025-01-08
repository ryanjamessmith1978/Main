// BasicGraphExample.cpp : https://www.youtube.com/watch?v=dhgKr8942rs
//
// Adjacency List

#include <iostream>
#include <list>
using namespace std;

class Graph
{
public:
	Graph(int size)
	{
		this->m_Size = size;
		listArray = new std::list<int>[size]; // list<int>[size];  -or- list<int>(size);
	}

	// assuming bidirectional edge
	void addEdge(int x, int y)
	{
		listArray[x].push_back(y);
		listArray[y].push_back(x);
	}	

	void printAdjList()
	{
		/*for (int i = 0; i < m_Size; i++)
		{
			std::cout << "Vertex " << i << "->";
			for (int neighbor : listArray[i])
			{
				std::cout << neighbor << ",";
			}
			std::cout << std::endl;
		}*/		

		// Made a MISTAKE thinking I needed to iterate over list with iterator in outer loop, even though it was an array
		for (int i = 0; i < m_Size; i++) 
		{
			std::cout << "Vertex " << i << "->";

			std::list<int>::iterator it = (listArray[i]).begin(); // iterator for this array index.

			for(; it != listArray[i].end(); it++) // inner loop
			{
				std::cout << *it << ", ";
			}
			std::cout << "\n";
		}
	}

private:
	int m_Size; // size
	std::list<int>* listArray;// = nullptr; // array of lists |  size not known at compile time.
};

int main()
{
	Graph g(4); // Array of (4) lists.
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.addEdge(1, 2);
	g.printAdjList();

	system("pause");
}


//		(0) Node ----------	 (1) Node
//				 \			/
//				  (2) Node     // 0-1-2 Nodes interconnected in a triangle
//					  |		   // Node 2 is connected to all Nodes.
//					  |
//				   (3) Node    // 2-3 Nodes connected

// ARRAY of Lists of Size v
// 0 -> 1,2  :  List L1
// 1 -> 2,0  :  List L2
// 2 -> 3, 0, 1 : List L3
// 3 -> 2 : List L4

// How to convert problem data to this structure?  General Rules?