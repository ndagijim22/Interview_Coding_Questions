#include <iostream>
#include <vector>

using namespace std;
/*
    intuition: Treat the 2d grid map as an undirected graph and there is an edge
                between two horizontally or vertically adjacent nodes of value '1'.

    Algo: Linear scan the 2d grid map, if a node contains a '1', then it is a root node
            that triggers a DFS. During DFS, every visited node should be
            set as '0' to mark as visited node. Count the number of root nodes that trigger
            DFS, this number would be the number of islands since each DFS starting at some
            root identifies an island.

    Time:O(M×N)O(M \times N)O(M×N) where M is the number of rows and
                N is the number of columns.
    space: worst case O(M×N)O(M \times N)O(M×N) in case that the grid map
                is filled with lands where DFS goes by M×NM \times NM×N deep.

*/
class Solution {
private:
  // Depth-First Search function to mark connected land cells as visited
  void dfs(vector<vector<char>>& grid, int r, int c) {
    int nr = grid.size();    // Number of rows in the grid
    int nc = grid[0].size(); // Number of columns in the grid

    // Mark the current cell as visited by changing its value to '0'
    grid[r][c] = '0';

    // Recursively explore adjacent cells (up, down, left, right) if they are valid land cells
    if (r - 1 >= 0 && grid[r - 1][c] == '1') 
        dfs(grid, r - 1, c);

    if (r + 1 < nr && grid[r + 1][c] == '1') 
        dfs(grid, r + 1, c);

    if (c - 1 >= 0 && grid[r][c - 1] == '1') 
        dfs(grid, r, c - 1);

    if (c + 1 < nc && grid[r][c + 1] == '1') 
        dfs(grid, r, c + 1);
  }

public:
  // Function to count the number of islands in a grid
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();    // Number of rows in the grid
    if (!nr) return 0;       // If grid is empty, return 0
    int nc = grid[0].size(); // Number of columns in the grid

    int num_islands = 0; // Counter for the number of islands
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        // If the current cell is unvisited land, mark the connected 
        //land cells and increment the counter
        if (grid[r][c] == '1') {
          ++num_islands;
          dfs(grid, r, c);
        }
      }
    }

    return num_islands; // Return the total number of islands
  }
};
