/*
    Build Order: you are given a list of projects and a list of dependencies (which is a list
    of pairs of projects, where the second project is dependent on the first project)
    All of a project's dependencies must be build before the project is. Find the order that
    will allow the projects to be built. if there is no valid build order, return an error

    Ex:
    input: 
        projects: a, b, c, d, e, f
        dependencies: (a, b), (f, b), (b, d), (f, a), (d, c)
    output:
        f, e, a, b, d, c

        SOURCE: https://www.geeksforgeeks.org/find-the-ordering-of-tasks-from-given-dependencies/
        WATCH THIS: https://www.youtube.com/watch?v=_BGK0kpE4oE 
        
*/
#include <iostream>
#include <stack>
#include <list>

using namespace std;

// std::stack<Project*> orderProjects(std::vector<Project*>& projects) {
//     //init stack
//     std::stack<Project*> stack;

//     //go thru project dependencies
//     for (Project* project : projects) {
//         //check if hasn't been visited
//         if (project->getState() == Project::BLANK) {
//             // do DFS on dependencies
//             doDFS(project, stack);
//             }
//         }
//     }
//     return stack;
// }

// void doDFS(Project* project, std::stack<Project*>& stack) {

//     if (project->getState() == Project::PARTIAL) {
//         return false; // Cycle detected
//     }

//     if (project->getState() == Project::BLANK) {
//         project->setState(Project::PARTIAL);
//         std::vector<Project*> children = project->getChildren();
//         for (Project* child : children) {
//             if (!doDFS(child, stack)) {
//                 return false;
//             }
//         }
//         project->setState(Project::COMPLETE);
//         stack.push(project);
//     }
//     // return true;
// }


            //TOPOLOGICAL SORT

// Class to represent a graph
class Graph {
    int V;
    list<int>* adj;
    void doDFS(int v, bool visited[],stack<int>& Stack);
 
public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};
 
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}
 
// A recursive function used by topologicalSort
void Graph::doDFS(int v, bool visited[],stack<int>& Stack){
    // Mark the current node as visited.
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    for (int neighbor : adj[v]){ 
        if (!visited[neighbor])
            doDFS(neighbor, visited, Stack);
    }
    // Push current vertex to stack which stores result
    Stack.push(v);
}
 
// The function to do Topological Sort.
// It uses recursive doDFS()
void Graph::topologicalSort(){
    stack<int> Stack;

    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            doDFS(i, visited, Stack);
 
    // Print contents of stack
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
     
    delete [] visited;
}
 
// Driver Code
int main(){
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