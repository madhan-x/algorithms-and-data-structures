# Data Structures & Algorithms Practice in C++

Hands-on implementations of data structures, algorithms, and problem-solving patterns — built through consistent practice using **C** and **C++**.

[![Build](https://github.com/madhan-x/algorithms-and-data-structures/actions/workflows/build.yml/badge.svg)](https://github.com/madhan-x/algorithms-and-data-structures/actions/workflows/build.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](./LICENSE)
[![C](https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![C++](https://img.shields.io/badge/C++-00599C?logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![LeetCode](https://img.shields.io/badge/LeetCode-FFA116?logo=leetcode&logoColor=white)](https://leetcode.com/)
[![Last Commit](https://img.shields.io/github/last-commit/madhan-x/algorithms-and-data-structures)](https://github.com/madhan-x/algorithms-and-data-structures/commits/main)

---

## Overview

This repository tracks my journey building strong foundations in **data structures**, **algorithms**, and **problem-solving patterns** — the core skills expected in software engineering interviews and competitive programming.

Each solution is implemented from first principles, with emphasis on understanding the technique over memorising the answer.

**Goals:**
- Develop deep intuition for time/space complexity
- Recognise problem-solving patterns (two pointers, sliding window, monotonic stack, etc.)
- Build a personal reference for technical interviews
- Maintain consistent daily practice

---

## Repository Stats

| Metric              | Count |
|---------------------|------:|
| Total solutions     |   113 |
| C implementations   |    25 |
| C++ implementations |    88 |
| LeetCode problems   |    11 |
| Topics covered      |    10 |

**LeetCode by difficulty:**
| Difficulty | Count |
|------------|------:|
| Easy       |     9 |
| Medium     |     1 |
| Hard       |     1 |

**Solutions by topic:**
| Topic          | Files |
|----------------|------:|
| Arrays         |    33 |
| Linked Lists   |    16 |
| Trees          |    15 |
| Stack          |     9 |
| Queue          |     8 |
| Two Pointers   |     6 |
| Recursion      |     6 |
| Basics         |     5 |
| Sorting        |     2 |
| Maths          |     1 |

---

## Table of Contents

- [Topics Covered](#topics-covered)
  - [Mathematics](#mathematics)
  - [C++ Fundamentals](#c-fundamentals)
  - [Arrays](#arrays)
  - [Two Pointers](#two-pointers)
  - [Recursion](#recursion)
  - [Linked Lists](#linked-lists)
  - [Stack](#stack)
  - [Queue](#queue)
  - [Trees](#trees)
- [LeetCode](#leetcode)
- [Patterns Practised](#patterns-practised)
- [Roadmap](#roadmap)
- [Conventions](#conventions)
- [Building Locally](#building-locally)
- [Connect](#connect)
- [License](#license)

---

## Topics Covered

### Mathematics
- nCr using factorial

### C++ Fundamentals
**Basics**
- Input / Output, Functions, STL vectors, Pattern printing

**Core Concepts**
- Data type modifiers, bitwise operators, operator precedence, associativity

### Arrays
- Check sorted array, missing number, maximum consecutive ones
- Kadane's algorithm, second largest element
- Best time to buy and sell stock, single number (XOR), array rotations
- Leaders in array, longest consecutive sequence, majority element
- Dutch National Flag algorithm, sliding window (max subarray of size K)
- Frequency of elements, first non-repeating element, smallest positive missing
- Equilibrium index, max difference, longest increasing/decreasing subarray, first duplicate

### Two Pointers
- Two sum, three sum, container with most water
- Trapping rain water, rotate array by K positions

### Recursion
- Print 1 to N, reverse array, palindrome check
- Binary search, power function, Fibonacci

### Linked Lists

**Singly / Doubly / Circular:** traversal, insert (begin / end), delete (begin / end)

**Additional:** find middle node

### Stack

**Problems:** implementation, insert at bottom, stock span, previous/next greater & smaller element, remove adjacent duplicates, min stack, postfix evaluation

**Patterns:** monotonic stack, previous/next element lookups

### Queue

- Implementation (array + STL), reverse queue, reverse first K elements
- Interleave queue, generate binary numbers, priority queue (max heap)

### Trees

- Tree creation, traversals (preorder, inorder, postorder, level order / BFS)
- Count leaves / internal nodes / total nodes, height, sum, maximum element
- Diameter, check identical, mirror, search/insert in BST
- Min element in BST

---

## LeetCode

### Arrays

**Easy**
- Two Sum (Brute Force)
- Search Insert Position (Linear Search)
- Remove Duplicates from Sorted Array (Two Pointers)
- Remove Element (Two Pointers)
- Merge Sorted Array
- Contains Duplicate (Hash Set)
- Majority Element (Brute Force)
- Move Zeroes (Two Pointers)

**Medium**
- Maximum Subarray (Kadane's Algorithm)

**Hard**
- Median of Two Sorted Arrays (Merge Approach)

### Strings

**Easy**
- Valid Anagram (Hash Map)

---

## Patterns Practised

These are the problem-solving techniques applied across solutions:

| Pattern             | Used In                                                          |
|---------------------|------------------------------------------------------------------|
| Two Pointers        | Remove duplicates, remove element, move zeroes, two sum, three sum |
| Sliding Window      | Maximum sum subarray of size K                                   |
| Kadane's Algorithm  | Maximum subarray                                                 |
| Dutch National Flag | Sort colors                                                      |
| Monotonic Stack     | Stock span, previous/next greater/smaller element                |
| Hash Set / Map      | Contains duplicate, valid anagram, intersection                  |
| Moore's Voting      | Majority element                                                 |
| Bit Manipulation    | Single number (XOR)                                              |
| Binary Search       | Search insert position                                           |
| Linked List Basics  | Insert/delete at both ends, traversal (singly / doubly / circular) |

---

## Roadmap

| Topic                | Status |
|----------------------|:------:|
| Arrays               |   ✅   |
| Linked Lists         |   ✅   |
| Stack                |   ✅   |
| Queue                |   ✅   |
| Recursion            |   ✅   |
| Binary Trees / BST   |   ✅   |
| Graphs               |   ⏳   |
| Dynamic Programming  |   ⏳   |
| Advanced STL         |   ⏳   |

**Current focus:** expanding LeetCode volume, especially Medium difficulty; introduction to Graphs.

---

## Conventions

Every solution follows a standard template — problem statement, pattern, approach, time/space complexity, and example. See [`CONTRIBUTING.md`](./CONTRIBUTING.md) for the full template.

Folder structure:
```
leetcode/<topic>/<difficulty>/<problem>-<technique>.ext
arrays/cpp/<problem>.cpp
linked-list/cpp/<problem>.cpp
```

Filename style: kebab-case with technique suffix on LeetCode solutions (e.g. `maximum-subarray-kadane.cpp`).

---

## Building Locally

The repo includes a CI workflow that compiles every source file with strict warnings. To reproduce locally:

```bash
# Compile-check a single C++ solution
g++ -std=c++17 -Wall -Wextra -Wpedantic -fsyntax-only <file>.cpp

# Compile-check a single C solution
gcc -std=c11 -Wall -Wextra -Wpedantic -fsyntax-only <file>.c
```

Requires `g++` / `gcc` (or any standards-compliant C/C++ compiler).

---

## Connect

- **GitHub:** [madhan-x](https://github.com/madhan-x)
- **LeetCode:** [madhan-x](https://leetcode.com/)

---

## License

Released under the [MIT License](./LICENSE).
