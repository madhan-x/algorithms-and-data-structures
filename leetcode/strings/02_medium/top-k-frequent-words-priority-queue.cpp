#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

/*
    LeetCode 692: Top K Frequent Words

    Difficulty: Medium
    Pattern: Hash Map + Max Heap / Priority Queue

    Approach:
    1. Count the frequency of every word using an unordered_map.
    2. Store {frequency, word} in a custom Max Heap.
    3. Higher frequency comes first.
    4. If frequencies are equal, lexicographically smaller word comes first.
    5. Pop the top k elements.

    Time Complexity: O(n + m log m)
    Space Complexity: O(m)

    n = number of words
    m = number of unique words
*/

class Solution {
public:

    // Custom comparator for the Max Heap
    struct Compare {
        bool operator()(const pair<int, string>& a,
                        const pair<int, string>& b) {

            // Higher frequency should come first
            if (a.first != b.first)
                return a.first < b.first;

            // If frequency is same, smaller word comes first
            return a.second > b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> mp;

        // Count frequency of each word
        for (string word : words) {
            mp[word]++;
        }

        // Max Heap
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            Compare
        > pq;

        // Insert {frequency, word} into heap
        for (auto x : mp) {
            pq.push({x.second, x.first});
        }

        vector<string> ans;

        // Extract top k frequent words
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

int main() {

    Solution solution;

    vector<string> words = {
        "i", "love", "leetcode", "i", "love", "coding"
    };

    int k = 2;

    vector<string> result = solution.topKFrequent(words, k);

    cout << "Top " << k << " frequent words: ";

    for (string word : result) {
        cout << word << " ";
    }

    cout << endl;

    return 0;
}
