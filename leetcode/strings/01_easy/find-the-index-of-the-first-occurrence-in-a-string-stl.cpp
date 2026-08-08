#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // string::find() returns the starting index
        // of needle inside haystack.
        size_t position = haystack.find(needle);

        // If needle is not found, find() returns string::npos.
        if (position == string::npos) {
            return -1;
        }

        return static_cast<int>(position);
    }
};

int main() {
    string haystack = "sadbutsad";
    string needle = "sad";

    Solution solution;

    int result = solution.strStr(haystack, needle);

    cout << "First occurrence index: " << result << endl;

    return 0;
}
