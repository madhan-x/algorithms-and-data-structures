#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m,
               vector<int>& nums2, int n)
    {
        int j = 0;

        // Copy nums2 elements into nums1
        for(int i = m; i < nums1.size(); i++)
        {
            nums1[i] = nums2[j];
            j++;
        }

        // Sort the merged array
        sort(nums1.begin(), nums1.end());
    }
};
