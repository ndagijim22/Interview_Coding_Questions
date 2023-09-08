/*
    String Compression: implement a method to perform basic string compression using the counts
            of repeated characters. For ex: the string aabccccaaa would become a2b1c5a3. if
            the compressed string would not become smaller than the original string, your
            method should return the original string. you can assume the stirng has onl uppercase
            and lowercase letters 
    Algo:
    1. iterate thru the string, copying charaters to a stringStream and counting 
        the repeats
    2. At each iteration check if teh current character is the same as the nect charater.
    3. if not add its compressed version to the result.
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Function to compress a string
string compress(const string& str) {
    stringstream compressed; // Using stringstream to build the compressed string
    int count = 0;

    for (int i = 0; i < str.length(); i++) {
        count++;

        // If the next character is different than the current, append the current character and its count
        if (i + 1 >= str.length() || str[i] != str[i + 1]) {
            compressed << str[i] << count;
            count = 0;
        }
    }

    // Convert stringstream to string
    string compressedStr = compressed.str();

    // Return the compressed string if it's shorter, else return the original string
    return compressedStr.length() > str.length() ? compressedStr : str;
}
