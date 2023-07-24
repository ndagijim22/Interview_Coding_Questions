/*
        TOPOLOGICAL SORT IMPLEMENTATION
    - It is a linear ordering of vertices such that for every directed edge u v,
        vertex u comes before v in the ordering
    - it is not possible if the graph is not DAG(Directed Acyclic Graph)
    - There can be more than one topological sorting order.
    - The first vertex in top sort is always a vertex with an in-degree of 0
    - top sort vs DFS:
        - in DFS, we print a vertex and then recursively call DFS for its adj vertices
            in top sort, we need to print vertex before its adj vertices

    Algorithm for top sort:
     - create a stack to store teh nodes
     - init visited array fo size N to keep the record of visited nodes
     - Run a loop from 0 till N
        - if the node is not marked True in visited array
            - call teh recursive function for top sort and perform the following steps
                - mark the current node as True in the visited array
                - Run a loop on all the nodes which has a directed edge to the current node
                    - if the node is not marked True in the visited array:
                        - recursively call top sort function on the node
                - Push the current node in the stack
    - print all the elements in the stack
*/
#include <iostream>
#include <stack>
#include <list>

using namespace std;

// A C++ program to print topological
// sorting of a DAG
 
// Class to represent a graph
class Graph {
    // No. of vertices'
    int V;
 
    // Pointer to an array containing adjacency listsList
    list<int>* adj;
 
    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[],
                             stack<int>& Stack);
 
public:
    // Constructor
    Graph(int V);
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints a Topological Sort of
    // the complete graph
    void topologicalSort();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}
 
// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int>& Stack)
{
    // Mark the current node as visited.
    visited[v] = true;
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    // Push current vertex to stack
    // which stores result
    Stack.push(v);
}
 
// The function to do Topological Sort.
// It uses recursive topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<int> Stack;
 
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function
    // to store Topological
    // Sort starting from all
    // vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
 
    // Print contents of stack
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
     
    delete [] visited;
}
 
// Driver Code
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is a Topological Sort of the given "
            "graph \n";
 
    // Function Call
    g.topologicalSort();
 
    return 0;
}