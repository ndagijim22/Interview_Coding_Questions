#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

/*
    Algorithm:
    1. Do pre-processing on given word list and find all possible generic states.
        use a queue<string, vector<string>>, key: generic word, value: list of words which have 
        the same intermediate word
    2. push beginWord and 1 to the queue(BFS), queue<pair<string, int>>: 1 represent the level
        of the node since we have to return the level of the node which will represent the shortest
        path from the beginWord
    3. To prevent a cycle, use visited queue<string, bool>
    4. while queue is not empty, get the current_word
    5. find all generic transformations of the current_word and find out if any of these transformations
        is also a transformation of other words in the word list. This is achieve by checking the all_comp_dict
    6. The list of words we get from all_comp_dict are all teh words which have a common intermediate
        state with the current_word. These new set of wrds will be the ajacent nodes to the curren-word
        and hence added to the queue
    7. For each word in teh list of intermediate words, append (word, level+1) into teh queue where level is the
        level for the current_word
    8. If you reach the desired word, its level would represent the shortest transformation sequene length
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int lenWord = beginWord.length();
        
        // Dictionary to hold combinations of words that can be formed by changing one letter 
        //at a time.
        unordered_map<string, vector<string>> allComboDict;
        
        // Populate the allComboDict with words that can be formed from wordList
        for (const string& word : wordList) {
            for (int i = 0; i < lenWord; i++) {
                string newWord = word.substr(0, i) + '*' + word.substr(i + 1, lenWord);
                allComboDict[newWord].push_back(word);
            }
        }
        
        // Queue for BFS
        queue<pair<string, int>> Q;
        Q.push({beginWord, 1}); // Start the BFS with the beginWord at level 1
        
        // Visited to avoid processing the same word multiple times.
        unordered_map<string, bool> visited;
        visited[beginWord] = true; // Mark the beginWord as visited
        
        while (!Q.empty()) {
            pair<string, int> node = Q.front();
            Q.pop();
            
            string word = node.first;
            int level = node.second;
            
            // Generate all possible words by changing one letter at a time
            for (int i = 0; i < lenWord; i++) {
                string newWord = word.substr(0, i) + '*' + word.substr(i + 1, lenWord);
                
                // Explore words that share the same intermediate state
                for (const string& adjacentWord : allComboDict[newWord]) {
                    if (adjacentWord == endWord) {
                        return level + 1; // If the endWord is found, return the level + 1
                    }
                    if (!visited.count(adjacentWord)) {
                        visited[adjacentWord] = true;
                        Q.push({adjacentWord, level + 1}); // Add adjacentWord to the queue for further exploration
                    }
                }
            }
        }
        
        return 0; // If no transformation sequence is found
    }
};

int main() {
    Solution solution;
    
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    int result = solution.ladderLength(beginWord, endWord, wordList);
    cout << "Ladder Length: " << result << endl;
    
    return 0;
}
