// BFS algorithm in C++
//Source: https://www.programiz.com/dsa/graph-bfs

#include <iostream>
#include <list>

using namespace std;

class Graph {
  private:
    int numVertices;
    list<int>* adjLists;
    bool* visited;

  public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
};
//constructor
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
}

void Graph::addEdge(int src, int dest) {
  adjLists[src].push_back(dest);
  // adjLists[dest].push_back(src); //undirected graph
}

// BFS algorithm
void Graph::BFS(int startVertex) {
  visited = new bool[numVertices];

  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  while (!queue.empty()) {
    
    int currVertex = queue.front();
    cout << currVertex << " ";
    queue.pop_front();

    for (int neighbor : adjLists[currVertex]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        queue.push_back(neighbor);
      }
    }
  }

  cout << endl;
}

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 1);

  g.BFS(2);

  return 0;
}