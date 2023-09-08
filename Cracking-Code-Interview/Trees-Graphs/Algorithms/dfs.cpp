// DFS algorithm in C++

#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph {
  private:
    int numVertices;
    list<int> *adjLists;
    bool *visited;

  public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
    void DFSIter(int vertex);
};

// Initialize graph
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  visited = new bool[vertices];
}

// Add edges
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_front(dest);
  adjLists[dest].push_front(src); //undirected graph
}

// DFS algorithm
// 1. RECURSIVE
void Graph::DFS(int vertex) {
  visited[vertex] = true;
  //create a temp list to hold neighbors of current vertex
  list<int> neighbors = adjLists[vertex];
  cout << vertex << " ";
  
  for (int i : neighbors)
    if (!visited[i])
      DFS(i);
}

//1. ITERATIVE
void Graph::DFSIter(int vertex){
  stack<int> stack;
  visited[vertex] = true;
  stack.push(vertex);

  while(!stack.empty()){
    int currentVertex = stack.top();
    stack.pop();

    cout << currentVertex << " ";

    for(int neighbor: adjLists[currentVertex]){
      if(!visited[neighbor]){
        visited[neighbor] = true;
        stack.push(neighbor);
      }
    }

  }

}

int main() {
  Graph g(5);
  g.addEdge(2, 1);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(2, 4);
  // g.addEdge(3, 2);

  // g.DFS(2);
  g.DFSIter(2);

  return 0;
}