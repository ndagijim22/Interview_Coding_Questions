/*
    You are given an array of logs. Each log is a space-delimited string of words,
    where the first word is the identifier. 

    There are two types of logs:
        - letter-logs: All words(except the identifier) consist of lowercae english letters
        - Digit-logs: All words(except the identifier) consists of digits

    reorder these logs so that:
        1. The letter-logs come before all digit-logs
        2. The letter-logs are sorted lexicographically by their contents. if their contents are the same,
                then sort them lexicographically by their identifiers
        3. The digit-logs maintain their relative ordering.

    return the final order fo the logs
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // Define a custom comparator to compare the logs
        auto myComp = [](const string& log1, const string& log2) {
            // Split each log into two parts: <identifier, content>
            size_t spacePos1 = log1.find(' ');
            size_t spacePos2 = log2.find(' ');

            string identifier1 = log1.substr(0, spacePos1);
            string identifier2 = log2.substr(0, spacePos2);

            string content1 = log1.substr(spacePos1 + 1);
            string content2 = log2.substr(spacePos2 + 1);

            // Check if the logs are letter-logs or digit-logs
            bool isDigit1 = isdigit(content1[0]);
            bool isDigit2 = isdigit(content2[0]);

            // Case 1: Both logs are letter-logs
            if (!isDigit1 && !isDigit2) {
                // First, compare the content of the letter-logs
                int cmp = content1.compare(content2);
                if (cmp != 0) {
                    return cmp < 0; // Sorting in ascending order of content
                }
                // If logs have the same content, compare the identifiers
                return identifier1.compare(identifier2) < 0; // Sorting in ascending order of identifier
            }

            // Case 2: One of the logs is a digit-log
            if (!isDigit1 && isDigit2) {
                // The letter-log comes before digit-logs
                return true;
            } else if (isDigit1 && !isDigit2) {
                // The digit-log comes after letter-logs
                return false;
            } else {
                // Case 3: Both logs are digit-logs
                // No change in the order of digit-logs
                return false;
            }
        };

        sort(logs.begin(), logs.end(), myComp);
        return logs;
    }
};

int main() {
    Solution solution;
    vector<string> logs = {
        "a1 9 2 3 1",
        "g1 act car",
        "zo4 4 7",
        "ab1 off key dog",
        "a8 act zoo"
    };

    vector<string> sortedLogs = solution.reorderLogFiles(logs);

    for (const string& log : sortedLogs) {
        cout << log << endl;
    }

    return 0;
}
