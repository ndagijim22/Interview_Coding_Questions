/*
    URLify:  Write a method to replace all the spaces in a string with ‘%20’. 
    You may assume that the string has sufficient space at the end to hold 
    the additional characters and that you are given the “true” length of the string.

    Algo: Aproach, manipulate the string backwards.
    - First count the number of spaces. we need 2 extra characters for each space since '%20'
        is 2 chars longer. so we double this count.
    - Then we walk backwards through the string, editing it. when we see a space, we replace it
    with "%20", if there are no space then we copy the original character.
*/

#include <iostream>
#include <string>

using namespace std;

// Count occurrences of 'target' between start (inclusive) and end (exclusive)
int countOfChar(char str[], int start, int end, char target) {
    int count = 0;
    for (int i = start; i < end; i++) {
        if (str[i] == target) {
            count++;
        }
    }
    return count;
}

// Replace spaces in 'str' with "%20"
void replaceSpaces(char str[], int trueLength) {
    int numberOfSpaces = countOfChar(str, 0, trueLength, ' ');
    int newIndex = trueLength - 1 + numberOfSpaces * 2;

    // If there are excess spaces, add a null character.
    // This indicates that the space after that point has not been replaced with "%20"
    if (newIndex + 1 < trueLength) {
        str[newIndex + 1] = '\0';
    }

    for (int oldIndex = trueLength - 1; oldIndex >= 0; oldIndex -= 1) {
        if (str[oldIndex] == ' ') {
            str[newIndex] = '0';
            str[newIndex - 1] = '2';
            str[newIndex - 2] = '%';
            newIndex -= 3;
        } else {
            str[newIndex] = str[oldIndex];
            newIndex -= 1;
        }
    }
}
