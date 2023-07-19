/*
    LINK: https://leetcode.com/discuss/interview-experience/1470686/amazon-online-assessment
    Follow link for description of the problem
    Solution: https://github.com/mxwllsmth/Code-Challenges/blob/main/Java%20Code%20Challenges/src/main/java/Easy_to_Medium/BuildingsWithWifi.java

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Create router class for easy reference to location and range
class Router {
public:
    int location;
    int range;

    Router(int location, int range) : location(location), range(range) {}
};

int getServedBuildings(vector<int> buildingCount, vector<int> routerLocation, vector<int> routerRange) {
    vector<int> buildingsServedArray = buildingCount;
    vector<bool> isBuildingServedArray(buildingCount.size(), false);
    vector<Router> routers;
    int buildingsServed = 0;

    // Loop and add location and range to routers list - (subtract 1 from location for 0 indexing)
    for (size_t i = 0; i < routerLocation.size(); i++) {
        routers.push_back(Router(routerLocation[i] - 1, routerRange[i]));
    }

    // Loop over routers
    for (const Router& i : routers) {
        // Check if router location minus range is in bounds (greater than or equal to 0) - set index
        int index = max(i.location - i.range, 0);
        // While index is in bounds and less than router location plus router range
        while (index < buildingsServedArray.size() && index <= i.location + i.range) {
            // Subtract 1 from each building in range
            buildingsServedArray[index] -= 1;
            // Check if building count <= 0 AND has not already been counted
            if (buildingsServedArray[index] <= 0 && !isBuildingServedArray[index]) {
                // Count and set to true
                buildingsServed++;
                isBuildingServedArray[index] = true;
            }
            // Increment index
            index++;
        }
    }
    // Return total buildings served
    return buildingsServed;
}

int main() {
    // Example usage:
    vector<int> buildingCount = {1,2,1,2,2};
    vector<int> routerLocation = {3,1};
    vector<int> routerRange = {1, 2};

    int servedBuildings = getServedBuildings(buildingCount, routerLocation, routerRange);
    cout << "Number of served buildings: " << servedBuildings << endl;

    return 0;
}

