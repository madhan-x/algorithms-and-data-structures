#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// LeetCode 347 - Top K Frequent Elements
// Approach: HashMap + Max-Heap (Priority Queue)
// - First pass: count the frequency of every element using an
//   unordered_map<int, int>.
// - Push each {frequency, value} pair into a max-heap. By default,
//   priority_queue orders by the first element of the pair, so the
//   entry with the highest frequency sits at the top.
// - Pop the top k entries and collect their values.
//
// Time Complexity:  O(n log n) — n pushes into a heap of size up to n.
// Space Complexity: O(n) — for the map and the heap.
//
// A more optimal variant uses a min-heap of size k, giving O(n log k).

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>> pq;
        unordered_map<int, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            pq.push({it->second, it->first});
        }

        vector<int> ans;
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

int main() {
    Solution sol;

    {
        vector<int> nums = {1, 1, 1, 2, 2, 3};
        int k = 2;
        vector<int> result = sol.topKFrequent(nums, k);
        cout << "Test 1: [";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i] << (i + 1 < result.size() ? "," : "");
        }
        cout << "]\n";
    }

    {
        vector<int> nums = {1};
        int k = 1;
        vector<int> result = sol.topKFrequent(nums, k);
        cout << "Test 2: [" << result[0] << "]\n";
    }

    {
        vector<int> nums = {4, 4, 4, 4, 5, 5, 5, 6};
        int k = 1;
        vector<int> result = sol.topKFrequent(nums, k);
        cout << "Test 3: [" << result[0] << "]\n";
    }

    {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int k = 3;
        vector<int> result = sol.topKFrequent(nums, k);
        cout << "Test 4: [";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i] << (i + 1 < result.size() ? "," : "");
        }
        cout << "]\n";
    }

    {
        vector<int> nums = {-1, -1, -2, -2, -2, 3, 3, 3, 3};
        int k = 2;
        vector<int> result = sol.topKFrequent(nums, k);
        cout << "Test 5: [";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i] << (i + 1 < result.size() ? "," : "");
        }
        cout << "]\n";
    }

    return 0;
}
