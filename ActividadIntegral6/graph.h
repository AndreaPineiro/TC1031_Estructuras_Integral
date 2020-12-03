// =================================================================
//
// File: graph.h
// Author: Andrea Pineiro Cavazos
// Description: Esta clase contiene la implementación de un 
// Grafo, con los algoritmos de DFS y BFS
//
// =================================================================


#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include "Trie.h"

using namespace std;

// =================================================================
// Definition of the Graph class
// =================================================================
class Graph {
	private:
		int nodes;
		vector<string> *adjList;
		int *adjMatrix;
		Trie *t;
		void addEdgeAdjList(string, string);
		void sortAdjList();
		bool contains(vector<string> &order, string busq);
	public:
		Graph();
		void loadGraphList(string, int, int);
		string printAdjList();
		string printAdjMat();
		string DFS(string, string);
		string BFS(string, string);
		void DFSHelper(string current, string goal, stack<string> &st, string paths[], vector<string> &visitedOrder);
		void BFSHelper(string current, string goal, queue<string> &qu, string paths[], vector<string> &visitedOrder);
		string printVisited(vector<string> &visitedOrder);
		string printPath(string path[], string inicio, string meta);
		string connectionsFromOrigin(string);
		bool NodeInGraph(string);
		void loadTrie();
	

};

// =================================================================
// Constructor. Initializes the value of Graph. The number of nodes
// is initialized to 0;
// Complexity O(1) Constant
// =================================================================
Graph::Graph(){
	nodes = 0;
}

// =================================================================
// Function that checks if a node exists on the graph. It uses the trie
// to check if it is in the graph.
// Complexity O(n) 
// =================================================================
bool Graph::NodeInGraph(string station){
	return (t->search(station));
}

void Graph::loadTrie(){
	t = new Trie();
	for (int i = 0; i < nodes; i++){
		t->insert(adjList[i][0]);
	}
}


// =================================================================
// This functions loads the edges and stores them in an adjacency 
// list. It receives the name of the file, and 2 integers. 
// The new value of nodes is the number of vertex. 
// Complexity: O(n) Linear. n -> number of lines. 
// =================================================================
void Graph::loadGraphList(string file, int ver, int arc){
	nodes = ver; // Sets the new number of nodes
	adjList = new vector<string>[nodes]; // Creates a vector of arrays to store the connections.  
	// Reads the file
	string ciudad1, ciudad2; 
	ifstream lee (file);
	if (lee.is_open()){
		while (lee.good()){
            getline(lee, ciudad1, ',');
            getline(lee, ciudad2, '\n');
            //cout << ciudad1 << endl << ciudad2 << endl;
            addEdgeAdjList(ciudad1, ciudad2); // Calls the function to store 
			// this new relation in the vector.
        }
		lee.close(); // Closes the file
	} else {
		cout << "Unable to open file"; 
	}
}

// =================================================================
// This functions receives a string; with that it gets 2 integers
// which are connected. And it adds each number in the other number's
// array. 
// Complexity: O(n) 
// =================================================================
void Graph::addEdgeAdjList(string u, string v){
	u = (u.substr(1, u.length()-1));
	v = (v.substr(1, v.length() - 3));
	// Flags to se which one has been added
	bool uSet = false;
	bool vSet = false;
	// This loop is to look for the node in which we'll make
	// the connections
	for (int i = 0; i < nodes; i ++){
		// If the list in that position is empty, it means the node is not in the 
		// vector, so we push that node on the position 0. The other positions
		// will repressent the adjacency.
		if (adjList[i].empty()){
			if (uSet == false){
				adjList[i].push_back(v); // Add the node on position 0
				adjList[i].push_back(u); // Add conection
				uSet = true;
				continue;
			} else if (vSet == false) {
				adjList[i].push_back(u); // Add the node on position 0
				adjList[i].push_back(v); // Add conection
				vSet = true;
				continue;
			}
		} else {
			// If it finds one of the nodes, it's only going to push back
			// the conection.
			if (adjList[i][0] == u && vSet == false){
				adjList[i].push_back(v);
				vSet = true;
			} if (adjList[i][0] == v && uSet == false){
				adjList[i].push_back(u);
				uSet = true;
			}
		}
	}

}


// =================================================================
// This functions prints the adjacency list. It prints the number of
// the vertex, and every element on the list of that position in the vector
// Ej. vertex 0 : 1 2 vertex 1 : 0 2 vertex 2 : 0 1
// Complexity: O(n^2) Cuadratic.
// =================================================================
string Graph::printAdjList(){
	stringstream aux;
	//sortAdjList(); // Calls the function to sort the lists
	for (int i = 0; i < nodes; i++){
		aux << "vertex " << adjList[i][0] << " : "; // prints vertex and the number
		for (int j = 1; j < adjList[i].size() - 1; j++){
			aux << adjList[i][j] << ", "; 
			// prints each element on the list at the position i on the vector.
		}
		aux <<  adjList[i][adjList[i].size()-1] << '\n';
	}
	return aux.str(); // returns the string
}


// =================================================================
// This functions prints all the connections, starting with a string
// the name of the subway station.
// =================================================================
string Graph::connectionsFromOrigin(string ciudad){
	stringstream aux;
	int pos = -1;
	
	// It looks in the trie if the station exists.
	if (NodeInGraph(ciudad) == false){
        aux << "\tLa estación no existe";
    } else {           
		for (int i = 0; i < nodes; i++){
			if (adjList[i][0] == ciudad){
		        pos = i;
	        }
		}

	    aux << "Vertex " << adjList[pos][0] << " : "; // prints vertex and the number
		for (int j = 1; j < adjList[pos].size()-1; j++){
			aux << adjList[pos][j] << ", "; 
			// prints each element on the list at the position i on the vector.
		}
		aux <<  adjList[pos][adjList[pos].size()-1] << '\n';
	}
	return aux.str();
}

// =================================================================
// This functions prints the DFS search (depth) starting from an initial
// node to the goal. 
// It uses an stack to keep track of the elements.
// Complexity O(n^2) 
// =================================================================
string Graph::DFS(string inicio, string meta){
	stringstream aux;
	stack<string> st; // Uses a stack to see which element is next
	vector<string> visitedOrder; // To print it in order, it uses a vector
	string path[nodes]; // Uses an array to store the parent of each node
	// Looks for the 2 cities in the Trie, to confirm that the stations 
	// exist, if not it returns a message
	if (NodeInGraph(inicio) == false && NodeInGraph(meta) == false){
        aux << "\tLas estaciones no existen.";
    } else if (NodeInGraph(inicio) == false){
        aux << "\tLa estación de origen no existe.";
    } else if (NodeInGraph(meta) == false){
        aux << "\tLa estación de destino no existe.";
    } else {                 
		for (int i = 0; i < nodes; i++){
			//visited[i] = false; // Sets each node to not visited
			path[i] = ""; // Sets each parent to be -1
		}
		st.push(inicio); // Adds the first node to the stack
		DFSHelper(inicio, meta, st, path, visitedOrder); // Calls the aux function
		aux <<  printPath(path, inicio, meta);
		// Prints the nodes visited, and the path from the start to the goal.
	
	}
	return aux.str();
}

// =================================================================
// This functions prints is an auxiliar for the DFS search (depth) 
// It uses the stack. It pushes the element, stores it, pops the 
// element from the stack and pushes all the children of that node
// Becuase it is a stack, it uses the element last added.
// Complexity O(n^2)  
// =================================================================
void Graph::DFSHelper(string current, string goal, stack<string> &st, string paths[], vector<string> &visitedOrder){
	if (current == goal){
		return;
		// If it has reached the goal, it stops
	} else if (st.empty()){
		cout << "Node not found"; // In case it does not find the node
	} else {
		current = st.top(); // The current node is the one on the top
		st.pop(); // Pops the element on the top of the stack
		//visited[current] = true; // Sets it to visited
		visitedOrder.push_back(current); // Adds the visited node to the vector
		
		int pos = -1;
		for (int i = 0; i < nodes; i++){
			if (adjList[i][0] == current){
				pos = i;
			}
		}
		
		if (pos != -1){
			// It checks every element connected to a node
			for (int i = 1; i < adjList[pos].size(); i++){
				if (contains(visitedOrder, adjList[pos][i]) == false){
					st.push(adjList[pos][i]);
					int posHijo = -1;
					for (int j = 0; j < nodes; j++){
						if (adjList[j][0] == adjList[pos][i]){
							posHijo = j;
						}
					} 
					// It pushes the children of a node if it has not been visited
					paths[posHijo] = current; // Sets the children's node to be current
				}
			}
			DFSHelper(current, goal, st,paths, visitedOrder); // Recursive function
		}
	}
}

// =================================================================
// This auxiliar functions receives a vector and a string, and returns
// true if the string is in the vector.
// =================================================================
bool Graph::contains(vector<string> &order, string busq){
	for (int i = 0; i < order.size(); i++){
		if (order[i] == busq){
			return true;
		}
	}
	return false;
}


// =================================================================
// This functions prints the BFS search (breadth) starting from an initial
// node to the goal. 
// It uses an queue to keep track of the elements.
// Complexity O(n^2)  
// =================================================================
string Graph::BFS(string inicio, string meta){
	stringstream aux;
	queue <string> qu; // Uses a queue to see which element is next
	vector<string> visitedOrder; // To print it in order, it uses a vector
	string path[nodes]; // Uses an array to store the parent of each node
	// Looks for the 2 cities in the Trie, to confirm that the stations 
	// exist, if not it returns a message
	if (NodeInGraph(inicio) == false && NodeInGraph(meta) == false){
        aux << "\tLas estaciones no existen.";
    } else if (NodeInGraph(inicio) == false){
        aux << "\tLa estación de origen no existe.";
    } else if (NodeInGraph(meta) == false){
        aux << "\tLa estación de destino no existe.";
    } else {
		for (int i = 0; i < nodes; i++){
			path[i] = ""; // Sets each parent to be -1
		}
		qu.push(inicio); // Adds the first node to the queue
		BFSHelper(inicio, meta, qu, path, visitedOrder); // Calls the aux function
		aux << printPath(path, inicio, meta);
	}
	// Prints the nodes visited, and the path from the start to the goal.
	return aux.str();
}

// =================================================================
// This functions prints is an auxiliar for the BFS search (breath) 
// It uses the queue. It pushes the element, stores it, pops the 
// element from the queue and pushes all the children of that node
// Becuase it is a queue, it uses the element first added.
// Complexity O(n^2)  
// =================================================================
void Graph::BFSHelper(string current, string goal, queue<string> &qu, string paths[], vector<string> &visitedOrder){
	if (current == goal){
		return;
		// If it has reached the goal, it stops
	} else if (qu.empty()){
		cout << "Node not found"; // In case it does not find the node
	} else {
		current = qu.front(); // The current node is the one on the front
		qu.pop(); // Pops the element on the front of the queue
		visitedOrder.push_back(current); // Adds the visited node to the vector
		
		int pos = -1;
		for (int i = 0; i < nodes; i++){
			if (adjList[i][0] == current){
				pos = i;
			}
		}
		if (pos != -1){
			// It checks every element connected to a node
			for (int i = 1; i < adjList[pos].size(); i++){
				if (contains(visitedOrder, adjList[pos][i]) == false){
					qu.push(adjList[pos][i]);
					int posHijo = -1;
					// Looks for the position it children on the vector of lists, by checking
					// the element on the position 0 of the list
					for (int j = 0; j < nodes; j++){
						if (adjList[j][0] == adjList[pos][i]){
							posHijo = j;
						}
					} 
					// It pushes the children of a node if it has not been visited
					// If the element on the path list is set to one it replaces the
					// value. If it has already been replaced it leaves it that way.
					if (paths[posHijo] == ""){
						paths[posHijo] = current;
					}
				}
			}
			BFSHelper(current, goal, qu, paths, visitedOrder); // Recursive function
		}
	}
}


// =================================================================
// This functions prints all the elements which were visited in order. 
// It prints all the elements in the vector visitedOrder.
// Complexity: O(n) Linear.
// =================================================================
string Graph::printVisited(vector<string> &visitedOrder){
	stringstream aux;
	aux << "visited:"; 
	for (int i = 0; i < visitedOrder.size(); i++){
		aux << " " << visitedOrder[i]; // Adds every visited node
		// to the stream
	}
	return aux.str();
}

// =================================================================
// This functions prints the path from the initial node to the goal. 
// It goes backwards to find the path and then prints it with a stack
// Complexity: O(n^2) .
// =================================================================
string Graph::printPath(string path[], string inicio, string meta){
	stringstream aux;

	stack<string> reverse; // Creates a stack to print the path reversed
	string node = meta; // Starts at the goal
	
	// It keeps going until it's reached the begining
	while (node != inicio){
		reverse.push(node); // Adds the node to the stack 
		int pos = -1;
		for (int i = 0; i < nodes; i++){
			//Looks for the position it has on the vector of lists, b checking
			// the element on the position 0 of the list
			if (adjList[i][0] == node){
				pos = i;
			}
		}
		node = path[pos]; // The new node is the value of path, which 
		//contains the parent of that node. 
	}
	reverse.push(inicio); // It adds the first node to the stack
	aux << " Path:";
	// While there's an element on the stack it prints the last one
	while (!reverse.empty()) {
		aux << " " << reverse.top();
		reverse.pop();
		if (!reverse.empty()){
			aux << ",";
		} else {
			aux << ".";
		}
	}
	return aux.str();
}


#endif

