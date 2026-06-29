# Contributing / Solution Template

This is a personal practice repo, but if you fork it, here's the convention so the codebase stays consistent.

## Solution File Template

Every new solution file must include this header:

```cpp
/*
 * Problem:    <LeetCode # + name>
 * Difficulty: <Easy | Medium | Hard>
 * Pattern:    <e.g. Two Pointers, Sliding Window, Kadane>
 * Link:       <https://leetcode.com/problems/...>
 *
 * Approach:   <2-3 lines explaining the core idea>
 *
 * Time:       O(?)
 * Space:      O(?)
 *
 * Example:
 *   Input:  <example input>
 *   Output: <example output>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // implementation
};

int main() {
    // minimal self-test
    return 0;
}
```

## Folder conventions

- Topic folders are named after the data structure / pattern: `arrays/`, `linked-list/`, `trees/`, `two-pointers/`, etc.
- Inside each topic: `c/` for C solutions, `cpp/` for C++ solutions.
- LeetCode problems go under `leetcode/<topic>/<difficulty>/<problem-name>-<technique>.cpp`.

## Filename conventions

- Kebab-case: `rotate-array-by-k.cpp`, not `rotateArrayByK.cpp`
- For LeetCode: include the technique in the filename when relevant (`-two-pointers`, `-hashset`, `-kadane`).
- This makes it obvious *how* you solved it, not just *what*.

## What reviewers care about

- ✅ Comment with time and space complexity
- ✅ One short paragraph explaining the approach
- ✅ Compiles clean with `g++ -std=c++17 -Wall -Wextra`
- ❌ Committed `.exe` / build artifacts (see `.gitignore`)
- ❌ Single mega-file with multiple problems