#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        // Split the input string into individual words.
        vector<string> words;
        string word;
        stringstream ss(s);

        while(ss >> word) {
            words.push_back(word);
        }

        // The number of pattern characters must match
        // the number of words.
        if(pattern.length() != words.size())
            return false;

        // Map pattern character -> word
        unordered_map<char, string> mp1;

        // Map word -> pattern character
        unordered_map<string, char> mp2;

        for(int i = 0; i < pattern.length(); i++) {

            char c = pattern[i];
            string w = words[i];

            // Check character -> word mapping.
            if(mp1.count(c)) {
                if(mp1[c] != w)
                    return false;
            }
            else {
                mp1[c] = w;
            }

            // Check word -> character mapping.
            // This prevents two different pattern characters
            // from mapping to the same word.
            if(mp2.count(w)) {
                if(mp2[w] != c)
                    return false;
            }
            else {
                mp2[w] = c;
            }
        }

        return true;
    }
};

int main() {

    Solution obj;

    string pattern = "abba";
    string s = "dog cat cat dog";

    cout << boolalpha << obj.wordPattern(pattern, s) << endl;

    return 0;
}

/*
Approach:
- Split the sentence into words.
- Ensure the number of words matches the pattern length.
- Maintain two mappings:
    1. pattern character -> word
    2. word -> pattern character
- Both mappings must remain consistent.

Pattern:
Two-Way Hash Map / One-to-One Mapping

Time Complexity:
O(n)

Space Complexity:
O(n)
*/
