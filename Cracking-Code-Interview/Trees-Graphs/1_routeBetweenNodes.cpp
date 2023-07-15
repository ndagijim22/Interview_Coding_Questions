/*
    Route Between Nodes: Given a directed graph and two nodes S and E, design an algorithm
    to find out whether there is a route between S and E

            ALGORITHM STEPS
    - BFS to traverse the graph
    - start w/ one node. during traversal check if other node is found
    - mark visited node as already visited to avoid cycles.
*/

#include <iostream>
#include <list>

using namespace std;

class Graph {
    int numVertices;
    list<int>* adjLists;
    bool* visited;

   public:
        Graph(int vertices);
        void addEdge(int src, int dest);
        void BFS(int startVertex);
        bool routeBetweenNodes(int start, int end);
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices];
}

void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    //undirected graph
    adjLists[dest].push_back(src);
}
// algorithm
bool Graph::routeBetweenNodes(int start, int end) {
    visited = new bool[numVertices];
    list<int> queue;

    //base case
    if(start == end)
        return true;

    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    visited[start] = true;
    queue.push_back(start);

    while (!queue.empty()) {
        int currVertex = queue.front();
        queue.pop_front();
      
            for (int neighbor: adjLists[currVertex]){
                if (!visited[neighbor]) {
                    if(neighbor == end){
                        return true;
                    }
                    if(!visited[neighbor]){
                        visited[neighbor] = true;
                        queue.push_back(neighbor);
                    }
                    
                }
            }   
    }
    //if BFS is complete without visiting end
    return false;
}

//Driver code
int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);


    if (g.routeBetweenNodes(0,9))
        cout << "Yes, there is a route\n";
    else
        cout << "No, there is NOT a route\n";

    return 0;
}