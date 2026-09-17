#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // Map characters from s -> t
        unordered_map<char, char> mp1;

        // Map characters from t -> s
        unordered_map<char, char> mp2;

        for(int i = 0; i < s.length(); i++) {

            // Check s -> t mapping
            if(mp1.count(s[i])) {

                // Existing mapping must remain consistent.
                if(mp1[s[i]] != t[i])
                    return false;
            }
            else {
                mp1[s[i]] = t[i];
            }

            // Check t -> s mapping
            if(mp2.count(t[i])) {

                // Prevent two different characters from mapping
                // to the same character.
                if(mp2[t[i]] != s[i])
                    return false;
            }
            else {
                mp2[t[i]] = s[i];
            }
        }

        return true;
    }
};

int main() {

    Solution obj;

    string s = "egg";
    string t = "add";

    cout << boolalpha << obj.isIsomorphic(s, t) << endl;

    return 0;
}

/*
Approach:
- Maintain two hash maps:
    1. s -> t
    2. t -> s
- Check that every existing mapping remains consistent.
- The reverse mapping prevents multiple characters from
  mapping to the same character.

Pattern:
Hash Map / Two-Way Character Mapping

Time Complexity:
O(n)

Space Complexity:
O(1)
- At most 256 character mappings for the standard character set.
*/
