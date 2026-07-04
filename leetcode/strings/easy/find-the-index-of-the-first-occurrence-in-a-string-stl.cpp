#include<string>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        // Find the first occurrence of needle
        int index = haystack.find(needle);

        // Return the index if found, otherwise return -1
        return index;
    }
};
