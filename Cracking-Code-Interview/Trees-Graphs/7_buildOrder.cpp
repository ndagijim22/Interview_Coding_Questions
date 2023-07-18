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
*/
// CPP program to find Topological sorting using
// DFS
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <utility>

// CPP program to find Topological sorting using
// DFS

using namespace std;

// Returns adjacency list representation of graph from
// given set of pairs.
vector<unordered_set<int> > make_graph(int numTasks,
			vector<pair<int, int> >& prerequisites)
{
	vector<unordered_set<int> > graph(numTasks);
	for (auto pre : prerequisites)
		graph[pre.second].insert(pre.first);
	return graph;
}

// Does DFS and adds nodes to Topological Sort
bool dfs(vector<unordered_set<int> >& graph, int node,
		vector<bool>& onpath, vector<bool>& visited,
								vector<int>& toposort)
{
	if (visited[node])
		return false;
	onpath[node] = visited[node] = true;
	for (int neigh : graph[node])
		if (onpath[neigh] || dfs(graph, neigh, onpath, visited, toposort))
			return true;
	toposort.push_back(node);
	return onpath[node] = false;
}

// Returns an order of tasks so that all tasks can be
// finished.
vector<int> findOrder(int numTasks, vector<pair<int, int> >& prerequisites)
{
	vector<unordered_set<int> > graph = make_graph(numTasks, prerequisites);
	vector<int> toposort;
	vector<bool> onpath(numTasks, false), visited(numTasks, false);
	for (int i = 0; i < numTasks; i++)
		if (!visited[i] && dfs(graph, i, onpath, visited, toposort))
			return {};
	reverse(toposort.begin(), toposort.end());
	return toposort;
}

int main()
{
	int numTasks = 4;
	vector<pair<int, int> > prerequisites;

	// for prerequisites: [[1, 0], [2, 1], [3, 2]]
	prerequisites.push_back(make_pair(1, 0));
	prerequisites.push_back(make_pair(2, 1));
	prerequisites.push_back(make_pair(3, 2));
	vector<int> v = findOrder(numTasks, prerequisites);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}
