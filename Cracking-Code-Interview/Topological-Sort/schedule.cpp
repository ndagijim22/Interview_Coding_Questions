/*
    Course Schedule: https://leetcode.com/problems/course-schedule/description/

    Steps:
    We always need adjList for applying DFS or topological sort.
    Make a adjList
    Populate indegrees
    removes edges of the vertices whose indegree is 0
    Do the same until we get the queue empty
    Now, check whether we traverse over all the vertices or not.(sizeof_totpologicalSort_vector==P).

*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canFinish(int n, vector<vector<int>>& prerequisites) {
    // Create an adjacency list to represent the graph
    vector<int> adj[n];
    
    // Create an array to keep track of indegrees for each vertex
    vector<int> indegree(n, 0);
    
    // Create a vector to store the topological ordering
    vector<int> ans;

    // Populate the adjacency list and indegree array based on prerequisites
    for(auto x: prerequisites){
        adj[x[0]].push_back(x[1]); // Add directed edge from x[0] to x[1]
        indegree[x[1]]++; // Increment indegree of x[1]
    }

    // Create a queue for BFS
    queue<int> q;

    // Enqueue all vertices with indegree 0 into the queue
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // Perform BFS
    while(!q.empty()){
        auto t = q.front();
        ans.push_back(t); // Add the current vertex to the topological ordering
        q.pop();

        // Traverse the neighbors of the current vertex
        for(auto x: adj[t]){
            indegree[x]--; // Decrement indegree of the neighbor
            if(indegree[x] == 0){
                q.push(x); // Enqueue neighbor if its indegree becomes 0
            }
        }
    }

    // If the topological ordering contains all vertices, return true; otherwise, false
    return ans.size() == n;
}
