# Data Structures & Algorithms in C / C++

**B.Tech AI & Data Science · DSA · C++ · C · Python** — implemented-from-scratch solutions across arrays, linked lists, trees, stacks, queues, strings, recursion, and LeetCode patterns. Consistent daily practice since March 2026.

[![Build Status](https://github.com/madhan-x/algorithms-and-data-structures/actions/workflows/build.yml/badge.svg)](https://github.com/madhan-x/algorithms-and-data-structures/actions/workflows/build.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](./LICENSE)
[![Last Commit](https://img.shields.io/github/last-commit/madhan-x/algorithms-and-data-structures)](https://github.com/madhan-x/algorithms-and-data-structures/commits/main)
[![C](https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![C++](https://img.shields.io/badge/C++-00599C?logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Python](https://img.shields.io/badge/Python-3776AB?logo=python&logoColor=white)](https://www.python.org/)
[![LeetCode](https://img.shields.io/badge/LeetCode-FFA116?logo=leetcode&logoColor=white)](https://leetcode.com/u/madhan-x)

---

## What this demonstrates

- **From-first-principles implementations** of every core data structure (linked lists, BSTs, stacks, queues) — not just library calls.
- **Pattern recognition across 42 LeetCode solutions** — two pointers, slow & fast, sliding window, Kadane's, Dutch National Flag, Moore's Voting, XOR, monotonic stack, priority queue, binary search, frequency counting, overflow bounds check, digit reversal, prefix sum, stack-based deletion.
- **Discipline** — 143 solutions committed, CI-enforced strict-warnings compilation (`-Wall -Wextra -Wpedantic`) on every push.
- **Readable, documented code** — every file documents problem, approach, time/space complexity (see [`CONTRIBUTING.md`](./CONTRIBUTING.md)).

---

## Repository Stats

| Metric              |  Count |
|---------------------|-------:|
| Total solutions     |    143 |
| C++ implementations |    120 |
| C implementations    |     23 |
| LeetCode solutions  |     42 |
| Topics covered      |     10 |

**LeetCode by difficulty**

| Difficulty | Count |
|------------|------:|
| Easy       |    27 |
| Medium     |    14 |
| Hard       |     1 |

**Solutions by topic**

| Topic          | Files |
|----------------|------:|
| Arrays         |    33 |
| Linked Lists   |    16 |
| Trees          |    15 |
| Stack          |     9 |
| Queue          |     8 |
| Recursion      |     6 |
| Two Pointers   |     6 |
| Basics         |     5 |
| Sorting        |     2 |
| Maths          |     1 |

---

## Table of Contents

- [What this demonstrates](#what-this-demonstrates)
- [Topics Covered](#topics-covered)
- [LeetCode by Difficulty](#leetcode-by-difficulty)
- [Patterns Practised](#patterns-practised)
- [Roadmap](#roadmap)
- [Conventions & Structure](#conventions--structure)
- [Building Locally](#building-locally)
- [Connect](#connect)
- [License](#license)

---

## Topics Covered

### Mathematics
- nCr using factorial

### C++ Fundamentals
- **Basics** — input/output, functions, STL vectors, pattern printing
- **Core concepts** — type modifiers, bitwise operators, precedence & associativity

### Arrays
- Check sorted, missing number, max consecutive ones
- Kadane's algorithm, second-largest element
- Best time to buy & sell stock, single number (XOR), array rotations
- Leaders in array, longest consecutive sequence, majority element
- Dutch National Flag, sliding window (max subarray of size K)
- Frequency counting, first non-repeating element, smallest positive missing
- Equilibrium index, max difference, longest increasing/decreasing subarray, first duplicate, pivot index

### Two Pointers
- Two sum, three sum, container with most water
- Trapping rain water, rotate array by K positions

### Recursion
- Print 1 to N, reverse array, palindrome check
- Binary search, power function, Fibonacci

### Linked Lists
- **Singly / doubly / circular** — traversal, insert (begin / end), delete (begin / end)
- Find middle node

### Stack
- **Problems** — implementation, insert at bottom, stock span, prev/next greater & smaller, remove adjacent duplicates, min stack, postfix evaluation, valid parentheses
- **Patterns** — monotonic stack, prev/next element lookups

### Queue
- Implementation (array + STL), reverse queue, reverse first K
- Interleave queue, generate binary numbers, priority queue (max heap)

### Trees
- Tree creation, traversals (preorder, inorder, postorder, level-order / BFS)
- Count leaves / internal nodes / total nodes, height, sum, max element
- Diameter, check identical, mirror, search/insert in BST, min element in BST

---

## LeetCode by Difficulty

### Arrays

**Easy (20)**
- Two Sum *(Brute Force)* · Best Time to Buy and Sell Stock · Search Insert Position *(Linear)* · Remove Duplicates from Sorted Array *(Two Pointers)* · Remove Element *(Two Pointers)* · Merge Sorted Array · Contains Duplicate *(Hash Set)* · Majority Element *(Brute Force)* · Majority Element *(Hash Map)* · Move Zeroes *(Two Pointers)* · Number of Good Pairs *(Hash Map)* · Find Pivot Index *(Brute Force)* · Find Pivot Index *(Prefix Sum)* · Sort Array By Parity *(Two Pointers)* · Squares of a Sorted Array *(Sort)* · Maximum Average Subarray I *(Sliding Window)* · Third Maximum Number *(Three Variables)* · Max Consecutive Ones *(Array Traversal)* · Intersection of Two Arrays *(Hash Set)* · Binary Search *(Binary Search)*

**Medium (6)**
- Maximum Subarray *(Kadane's Algorithm)* · Top K Frequent Elements *(Hash Map + Priority Queue)* · 3Sum *(Two Pointers)* · Sort Colors *(Dutch National Flag)* · Container With Most Water *(Two Pointers)* · Subarray Sum Equals K *(Prefix Sum + Hash Map)*

**Hard (1)**
- Median of Two Sorted Arrays *(Merge Approach)*

### Strings

**Easy (5)**
- Valid Anagram *(Hash Map)* · Find the Index of the First Occurrence in a String *(STL)* · Reverse String *(Two Pointers)* · First Unique Character in a String *(Hash Map)*
  - _Note: two implementation variants of LC 28 (Find First Occurrence) are kept side-by-side — `find-first-occurrence-stl.cpp` is the templated/main-tested version, `find-the-index-of-the-first-occurrence-in-a-string-stl.cpp` is the earlier draft._

**Medium (3)**

- Maximum Number of Vowels in a Substring of Given Length *(Sliding Window)* · Longest Substring Without Repeating Characters *(Sliding Window + Hash Map)* · Longest Repeating Character Replacement *(Sliding Window + Hash Map)*

### Stack

**Easy (1)**
- Valid Parentheses *(Stack)*

**Medium (1)**
- Removing Stars From a String *(Stack)*

### Linked List

**Easy (1)**
- Middle of the Linked List *(Slow & Fast Pointers)*

**Medium (2)**
- Remove Nth Node From End of List *(Two Pointers)*
  - _Note: `remove-nth-node-from-end-twopointers.cpp` (templated, in `02_medium/`) and `remove-nth-node-from-end-of-list-two-pointers.cpp` (legacy, in `medium/`) both solve LC 19; the newer file is the recommended version._

### Maths

**Easy (1)**
- Palindrome Number *(Digit Reversal)*

**Medium (1)**
- Reverse Integer *(Overflow Bounds Check)*

---

## Patterns Practised

| Pattern             | Applied In |
|---------------------|------------|
| Two Pointers        | Remove duplicates, remove element, move zeroes, two sum, three sum, sort array by parity, squares of sorted array, container with most water, find first occurrence, reverse string, remove nth node from end of list, middle of the linked list |
| Sliding Window      | Maximum sum subarray of size K, Maximum Average Subarray I, Maximum Number of Vowels, Longest Substring Without Repeating Characters, Longest Repeating Character Replacement |
| Stack               | Valid parentheses, removing stars from a string |
| Kadane's Algorithm  | Maximum subarray |
| Dutch National Flag | Sort colors |
| Monotonic Stack     | Stock span, prev/next greater/smaller |
| Hash Set / Map      | Contains duplicate, valid anagram, number of good pairs, majority element, intersection of two arrays, first unique character, top K frequent elements |
| Priority Queue / Heap | Top K frequent elements, max heap (priority queue) |
| Moore's Voting      | Majority element |
| Bit Manipulation    | Single number (XOR) |
| Binary Search       | LC 704 binary search, recursion-based binary search |
| Prefix Sum          | Find pivot index, subarray sum equals K |
| Linked List Basics  | Insert/delete at both ends, traversal (singly / doubly / circular) |

---

## Roadmap

| Phase | Topic                       | Status |
|-------|-----------------------------|:------:|
| Core  | Arrays, Linked Lists, Stack, Queue | ✅ |
| Core  | Recursion, Binary Trees / BST      | ✅ |
| Core  | Strings, Sorting                    | ✅ |
| Next  | Graphs (BFS / DFS / Topo Sort)      | 🔄 |
| Next  | Dynamic Programming                 | 🔄 |
| Next  | Advanced STL (maps, sets, heaps)    | 🔄 |
| Scale | LeetCode Medium / Hard volume       | 🔄 |

**Current focus:** Graphs foundations · 30 Medium LeetCode target · one new solution per day.

---

## Conventions & Structure

Every solution follows a documented template — problem statement, pattern, approach, time/space complexity, example. See [`CONTRIBUTING.md`](./CONTRIBUTING.md) for the full template.

```
algorithms-and-data-structures/
├── arrays/                # topic folders
│   ├── c/
│   └── cpp/
├── linked-list/
├── trees/
├── stack/
├── queue/
├── recursion/
├── sorting/
├── two-pointers/
├── maths/
├── basics/
└── leetcode/
    └── <topic>/<difficulty>/<problem>-<technique>.ext
```

- **Filenames:** kebab-case · technique suffix on LeetCode (e.g. `maximum-subarray-kadane.cpp`)
- **Languages:** C (`<topic>/c/`), C++ (`<topic>/cpp/`) — kebab-case file names in either language
- **CI:** every push compiles all `.c` and `.cpp` files with `-Wall -Wextra -Wpedantic`

---

## Building Locally

```bash
# Compile-check a single C++ solution
g++ -std=c++17 -Wall -Wextra -Wpedantic -fsyntax-only <file>.cpp

# Compile-check a single C solution
gcc -std=c11 -Wall -Wextra -Wpedantic -fsyntax-only <file>.c
```

Requires `g++` / `gcc` (or any standards-compliant C/C++ compiler).

---

## Connect

- **GitHub** — [@madhan-x](https://github.com/madhan-x)
- **LeetCode** — [madhan-x](https://leetcode.com/u/madhan-x)
- **LinkedIn** — [Madhan Thalloju](https://www.linkedin.com/in/madhan-thalloju-7a79903ab)

---

## License

Released under the [MIT License](./LICENSE).
