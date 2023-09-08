/*
    Robot in a Grid: imagine a robot sitting on the upper left corner of grid with r rows
    and c columns. The robot can only move in two directions, right and down, but certain cells are 
    off limits such that the robot cannot step on them. Design an algo. to find a path for the robot
    from the top left to the bottom right

    Algo: work backwards by starting from the last cell and try to find a path
    to each of its adjacent cells recursively.
*/
//Question 8.2 C++ contrasting solution

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Point {
    int row;
    int column;
    Point(int r, int c) : row(r), column(c) {}
};



//////////////////////////////////////////////////////
//Implementation with memoization/caching
//////////////////////////////////////////////////////

//Checks if path is valid and simultaneously adds position to a result vector
bool getPath(int** matrix, int currRow, int currColumn, vector<Point*>& path, 
    unordered_set<Point*>& duplicateVisits){
    
    //if out of bounds or curr position is off limits, return false
    if (currRow < 0 || currColumn < 0 || matrix[currRow][currColumn] == -1){
        return false;
    }
    
    Point* currPos = new Point(currRow, currColumn);
    
    //If we have already visited this position, then return false
    if (duplicateVisits.find(currPos) != duplicateVisits.end()){
        return false;
    }
    
    
    bool atOrigin = currRow == 0 && currColumn == 0;
    
    //Everytime robot moves up or left and it is a valid position, add the point to result vector
    if (atOrigin || getPath(matrix, currRow-1, currColumn, path, duplicateVisits) 
                 || getPath(matrix, currRow, currColumn-1, path, duplicateVisits)){
        path.push_back(currPos);
        return true;
    }
    
    //Keep track of already visited points
    duplicateVisits.insert(currPos);
    
    return false;
}

vector<Point*> getPath(int** matrix, int rows, int columns){
    //create result vector
    vector<Point*> path;
    
    //create unordered set to keep track of already visited points
    unordered_set<Point*> duplicateVisits;
    
    //Bounds checking
    if (rows != 0 || matrix != nullptr){
        //Start checking positions from bottom right to top left
        if (getPath(matrix, rows - 1, columns - 1, path, duplicateVisits)){
            return path;
        }
    }
    //Return an empty vector indicating path does not exist
    return path;
    
}


//////////////////////////////////////////////////////
//Implementation without memoization/caching
//////////////////////////////////////////////////////



//Checks if path is valid and simultaneously adds position to a result vector
//bool getPath(int** matrix, int currRow, int currColumn, vector<Point*>& path){
//    
//    //if out of bounds or curr position is off limits, return false
//    if (currRow < 0 || currColumn < 0 || matrix[currRow][currColumn] == -1){
//        return false;
//    }
//    
//    bool atOrigin = currRow == 0 && currColumn == 0;
//    
//    //Everytime robot moves up or left and it is a valid position, add the point to result vector
//    if (atOrigin || getPath(matrix, currRow-1, currColumn, path) || getPath(matrix, currRow, currColumn-1, path)){
//        Point* currPos = new Point(currRow, currColumn);
//        path.push_back(currPos);
//        return true;
//    }
//    return false;
//    
//    
//    
//    
//}
//
//vector<Point*> getPath(int** matrix, int rows, int columns){
//    //create result vector
//    vector<Point*> path;
//    
//    //Bounds checking
//    if (rows != 0 || matrix != nullptr){
//        //Start checking positions from bottom-right
//        if (getPath(matrix, rows - 1, columns - 1, path)){
//            return path;
//        }
//
//        
//    }
//    //Otherwise return an empty vector indicating path does not exist
//    return path;
// 
//}

