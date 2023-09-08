#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
    Algo:
    1. init a queue to keep track of nodes with 0 in degree
    2. loop thru edges in input adn cread adj list and a map of node and its in-degree
    3. add all nodes with 0 in-degree to queue
    4. while queue is not empty
        a. pop node from queue, call it N
        b. For all N neighbors, decrement their in-degree by 1. if any becomes zero, add them to queue
        c. add n to top sort list

    time: O(V + E): V is num of vertices and E is num of edges. we iterate thru all vertices and for 
                        each vertex we iterate throu its edges
    space: O(V + E): same as above b/c we need to store each in the queue at least once.
*/
class Solution {
public:
    vector<int> findOrder(int numCources, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCources);                   // {prerequisite-course : [list of next courses]}
        vector<int> ans, indegree(numCources);               // indegree[i] denotes number of prerequisite courses for ith course
        for(auto& pre : prerequisites) 
            adjlist[pre[1]].push_back(pre[0]),            // forming adjacency list graph
            indegree[pre[0]]++;                     
        
        queue<int> q;
        for(int i = 0; i < numCources; i++)
            if(indegree[i] == 0) q.push(i);         // we can start with courses having no prequisites
        
        while(size(q)) {
            auto cur = q.front(); 
            q.pop();
            ans.push_back(cur);                     // cur has no remaining pre courses, so we can take it now
            for(auto nextCourse : adjlist[cur]){
                indegree[nextCourse]--; 
                if(indegree[nextCourse] == 0)     // if there's a next course having 0 prequisite remaining,
                    q.push(nextCourse);
            }             // then we can take it
        }
        if(size(ans) == numCources) return ans;              // ordering exists where all courses can be finished
        return {};                                      
    }
};