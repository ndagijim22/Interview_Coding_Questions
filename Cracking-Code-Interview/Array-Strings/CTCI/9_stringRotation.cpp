

#include <iostream>
#include <string>

using namespace std;

// Function to check if one string is a rotation of another
bool isRotation(const string& s1, const string& s2) {
    int len = s1.length();

    // Check that s1 and s2 are equal length and not empty
    if (len == s2.length() && len > 0) {
        // Concatenate s1 and s2 within a new buffer
        string s1s1 = s1 + s1;

        // Check if s2 is a substring of s1s1
        return s1s1.find(s2) != string::npos;
    }
    return false;
}
