/*
        Kahn's Algorithm
    it is commonly used to determine the order of tasks or dependencies.
    Kahn's algo. works by repeatedly finding vertices with no incoming edges(in-degree = 0)
    and removing them from the graph, along with their outgoing edges. This process is repeated
    until all vertices are processed. The order in which the vertices are removed gives a valid
    topological ordering

    Algorithm steps:
    1. calculate the in-degree(# of incoming edges) for all vertices
    2. init a queue and enqueue all vertices with an in-degree of 0
    3. while the queue is not empty:
        - dequeue vertex
        - Add it to the sorted order
        - decrement the in-degrees of its adj vertices
        - if an adj vertex's in-degree becomes 0, enqueue it

    4. if the sorted order contains all vertices, return it as the topological order.

    time: O(v + E) where v is # of vertices and E is # of edges
    space: same O(v + E) 

*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int numVertices; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    // Constructor to initialize the graph with 'v' vertices
    Graph(int vertex) : numVertices(vertex), adj(vertex) {}

    // Function to add an edge from vertex 'source' to vertex 'dest'
    void addEdge(int src, int dest) {
        adj[src].push_back(dest);
    }

    // Function to perform topological sort using Kahn's algorithm
    vector<int> topologicalSort() {
        vector<int> inDegree(numVertices, 0);
        
        // Calculate in-degrees of vertices
        for (int i = 0; i < numVertices; ++i) {
            for (int neighbor : adj[i]) {
                inDegree[neighbor]++;
            }
        }

        queue<int> q;
        // Enqueue vertices with in-degree 0
        for (int v = 0; v < numVertices; ++v) {
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            result.push_back(currentVertex);

            // Decrement in-degree and enqueue if it becomes 0
            for (int neigbor : adj[currentVertex]) {
                inDegree[neigbor]--;
                if (inDegree[neigbor] == 0) {
                    q.push(neigbor);
                }
            }
        }

        return result;
    }
};

int main() {
    Graph g(6); // Create a graph with 6 vertices

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    vector<int> result = g.topologicalSort();

    cout << "Topological Order: ";
    for (int vertex : result) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
