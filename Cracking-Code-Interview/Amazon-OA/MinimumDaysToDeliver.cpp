/*
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getSmallestValue(const vector<int>& inputList) {
    return *min_element(inputList.begin(), inputList.end());
}

int main() {
    vector<int> parcels = {2, 4, 3, 1};
    int numberOfDaysRequired = 0;

    while (!parcels.empty()) {
        int smallestValue = getSmallestValue(parcels);
        for (int i = 0; i < parcels.size(); i++) {
            parcels[i] -= smallestValue;
        }
        if (!parcels.empty()) {
            numberOfDaysRequired++;
            parcels.erase(remove(parcels.begin(), parcels.end(), 0), parcels.end());
        }
    }

    cout << "Number of days required for delivering all the parcels: " << numberOfDaysRequired << endl;

    return 0;
}
