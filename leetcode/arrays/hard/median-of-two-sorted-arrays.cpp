#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1,
                                  vector<int>& nums2)
    {
        vector<int> arr;

        int i = 0;
        int j = 0;

        // Merge both sorted arrays
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] < nums2[j])
            {
                arr.push_back(nums1[i]);
                i++;
            }
            else
            {
                arr.push_back(nums2[j]);
                j++;
            }
        }

        // Add remaining elements of nums1
        while(i < nums1.size())
        {
            arr.push_back(nums1[i]);
            i++;
        }

        // Add remaining elements of nums2
        while(j < nums2.size())
        {
            arr.push_back(nums2[j]);
            j++;
        }

        int n = arr.size();

        // Odd size
        if(n % 2 == 1)
        {
            return arr[n / 2];
        }

        // Even size
        return (arr[n / 2] + arr[(n / 2) - 1]) / 2.0;
    }
};
