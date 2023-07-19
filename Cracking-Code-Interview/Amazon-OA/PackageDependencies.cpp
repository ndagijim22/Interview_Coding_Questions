/*
    LINK: https://leetcode.com/discuss/interview-question/1031933/amazon-onsite-sde2-package-dependencies
    a) You have a package repository in which there are dependencies between packages for building like package A has to be built before package B. If you are given dependencies between the packages and package name x, we have find the build order for x.
    Ex: A → {B,C}
    B → {E}
    C → {D,E,F}
    D → {}
    F → {}
    G → {C}

    For package A, build order is E B F D C A (may not unique)

    Given a function Set getDependencies (Package packageName) which returns a set of dependencies for a given package name, write a method List getBuildOrder(Package packageName) which returns the build order

    b) How would you handle cyclic dependencies (Algo only)
*/
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stdexcept>

using namespace std;

vector<string> packageOrder(const unordered_map<string, vector<string>>& dependencies, const string& p) {
    // Find the subset using bfs
    queue<string> queue;
    queue.push(p);
    unordered_set<string> subset;
    subset.insert(p);

    while (!queue.empty()) {
        string cur = queue.front();
        queue.pop();
        for (const string& dep : dependencies.at(cur)) {
            if (subset.insert(dep).second) {
                queue.push(dep);
            }
        }
    }

    // Build graph and indegree for topological sort
    unordered_map<string, int> indegree;
    unordered_map<string, vector<string>> graph; // dep to packages
    vector<string> order;
    for (const string& pac : subset) {
        indegree[pac] = dependencies.at(pac).size();

        for (const string& dep : dependencies.at(pac)) {
            graph[dep].push_back(pac);
        }
    }

    // Topological sort
    queue = queue<string>();
    for (const string& key : subset) {
        if (indegree[key] == 0) {
            order.push_back(key);
            queue.push(key);
        }
    }

    while (!queue.empty()) {
        string pac = queue.front();
        queue.pop();
        for (const string& next : graph[pac]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                order.push_back(next);
                queue.push(next);
            }
        }
    }

    // If we can finish the subset, that means there is no cycle
    if (order.size() == subset.size()) {
        return order;
    }

    throw invalid_argument("Circle found");
}

int main() {
    // Example usage:
    unordered_map<string, vector<string>> dependencies = {
        {"A", {"B", "C"}},
        {"B", {"D", "E"}},
        {"C", {}},
        {"D", {"F"}},
        {"E", {"F"}},
        {"F", {}}
    };

    string package_name = "A";
    vector<string> order = packageOrder(dependencies, package_name);

    cout << "Package order starting from " << package_name << ": ";
    for (const string& package : order) {
        cout << package << " ";
    }
    cout << endl;

    return 0;
}
