#include <string>

using namespace std;

/*
    Algo: https://www.youtube.com/watch?v=OndJpimZorQ
*/
class Solution {
    int mins[4] = { 600, 60, 10, 1 };  // Array to represent the minutes at each digit position
public:
    string nextClosestTime(string time) {
        if (time[0] == time[1] && time[1] == time[3] && time[3] == time[4])
            return time;  // If all digits are the same, return the input time
        
        int cur = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));  // Convert input time to minutes
        string next = "0000";  // Initialize a string to store the next closest time
        
        // Loop through all possible times in a 24-hour cycle (1440 minutes)
        for (int i = 1; i < 1440; i++) {
            int m = (cur + i) % 1440;  // Calculate the minutes for the next time
            
            // Check if m is a valid "Next time"
            int d = 0;
            for (; d < 4; d++) {
                next[d] = '0' + m / mins[d];  // Calculate the digit at the current position
                m = m % mins[d];  // Update remaining minutes after subtracting current position
                if (time.find(next[d]) == string::npos)
                    break;  // If the digit is not found in the input time, break
            }
            if (d == 4) break;  // If all digits are valid, exit the loop
        }
        
        // Return the formatted next closest time
        return next.substr(0, 2) + ":" + next.substr(2, 2);
    }
};