/*

*/
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> getLogsOverThreshold(const vector<string>& logs, int threshold) {
    map<int, int> tm; 
    
    for (const string& log : logs) {
        cout << log << endl;

        // Split the log by space
        vector<string> s;
        string token;
        stringstream ss(log);
        while (ss >> token) {
            s.push_back(token);
        }

        int sender = stoi(s[0]);
        int receiver = stoi(s[1]);

        tm[sender] = tm[sender] + 1; // Increment the count for sender

        if (sender != receiver) {
            tm[receiver] = tm[receiver] + 1; // Increment the count for receiver
        }
    }

    vector<string> ans;

    for (const auto& entry : tm) {
        if (entry.second >= threshold) {
            ans.push_back(to_string(entry.first));
        }
    }

    return ans;
}

int main() {
    // Example usage:
    vector<string> logs = {"88 99 200", "88 99 300", "99 32 100", "12 12 15"};
    int threshold = 2;

    vector<string> result = getLogsOverThreshold(logs, threshold);

    cout << "Logs over threshold: ";
    for (const string& log : result) {
        cout << log << " ";
    }
    cout << endl;

    return 0;
}
