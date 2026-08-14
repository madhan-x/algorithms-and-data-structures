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
- **Pattern recognition across <!-- AUTO-LC-COUNT -->67<!-- /AUTO-LC-COUNT --> LeetCode solutions** — two pointers, slow & fast, sliding window, Kadane's, Dutch National Flag, Moore's Voting, XOR, monotonic stack, priority queue, binary search, frequency counting, overflow bounds check, digit reversal, prefix sum, stack-based deletion.
- **Discipline** — <!-- AUTO-TOTAL-COUNT -->168<!-- /AUTO-TOTAL-COUNT --> solutions committed, CI-enforced strict-warnings compilation (`-Wall -Wextra -Wpedantic`) on every push.
- **Readable, documented code** — every file documents problem, approach, time/space complexity (see [`CONTRIBUTING.md`](./CONTRIBUTING.md)).

---

## Repository Stats

<!-- AUTO-STATS:START -->
| Metric              |  Count |
|---------------------|-------:|
| Total solutions     |   168 |
| C++ implementations |   145 |
| C implementations   |    23 |

**Solutions by topic**

| Topic          | Files |
|----------------|------:|
| Arrays         |    33 |
| Linked List    |    16 |
| Trees          |    15 |
| Stack          |     9 |
| Queue          |     8 |
| Recursion      |     6 |
| Two Pointers   |     6 |
| Basics         |     5 |
| Sorting        |     2 |
| Maths          |     1 |

**LeetCode by difficulty** (67 solved on [LeetCode profile](https://leetcode.com/u/madhan-x))

| Difficulty | Count |
|------------|------:|
| Easy       |    37 |
| Medium     |    29 |
| Hard       |     1 |
<!-- AUTO-STATS:END -->

> Stats are auto-generated from the repo by `scripts/update-readme-stats.py`
> (runs on every commit via the pre-commit hook on laptop, and on every
> push to `main` via the `Refresh README` GitHub Action — so it works
> from mobile clients too). Don't edit the table above by hand — it
> gets overwritten.

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

<!-- AUTO-LEETCODE:START -->
### Arrays

**Easy (22)**
- `binary-search.cpp` · `contains-duplicate-hashset.cpp` · `find-pivot-index-bruteforce.cpp` · `find-smallest-letter-greater-than-target-binary-search.cpp` · `intersection-of-two-arrays-hash-set.cpp` · `majority-element-bruteforce.cpp` · `majority-element-hashmap.cpp` · `max-consecutive-ones.cpp` · `maximum-average-subarray-i-sliding-window.cpp` · `merge-sorted-array.cpp` · `move-zeroes-two-pointers.cpp` · `number-of-good-pairs-hashmap.cpp` · `pivot-index-prefixsum.cpp` · `plus-one.cpp` · `remove-duplicates-from-sorted-array.cpp` · `remove-element.cpp` · `search-insert-position-linear.cpp` · `sort-array-by-parity-two-pointers.cpp` · `squares-of-a-sorted-array-sort.cpp` · `squares-of-sorted-array-sort.cpp` · `third-maximum-number-three-variables.cpp` · `two-sum-bruteforce.cpp`

**Medium (13)**
- `container-with-most-water-two-pointers.cpp` · `find-first-and-last-position-of-element-binary-search.cpp` · `find-minimum-in-rotated-sorted-array-binary-search.cpp` · `find-the-smallest-divisor-given-a-threshold-binary-search-on-answer.cpp` · `koko-eating-bananas-binary-search-on-answer.cpp` · `maximum-subarray-kadane.cpp` · `product-of-array-except-self-prefix-suffix.cpp` · `rotate-array-reversal-algorithm.cpp` · `search-in-rotated-sorted-array-binary-search.cpp` · `sort-colors-dutch-national-flag.cpp` · `subarray-sum-equals-k-prefix-sum-hash-map.cpp` · `three-sum-two-pointers.cpp` · `top-k-frequent-elements-priorityqueue.cpp`

**Hard (1)**
- `median-of-two-sorted-arrays.cpp`

### Linked List

**Easy (7)**
- `convert-binary-number-in-a-linked-list-to-integer.cpp` · `intersection-of-two-linked-lists-two-pointers.cpp` · `linked-list-cycle-floyd-cycle-detection.cpp` · `merge-two-sorted-lists-dummy-node.cpp` · `remove-duplicates-from-sorted-list.cpp` · `remove-linked-list-elements.cpp` · `reverse-linked-list-iterative.cpp`

**Medium (11)**
- `add-two-numbers-linked-list.cpp` · `delete-node-in-a-linked-list.cpp` · `linked-list-cycle-ii-floyd-cycle-detection.cpp` · `middle-of-the-linked-list-slow-fast.cpp` · `odd-even-linked-list.cpp` · `palindrome-linked-list-fast-slow-reversal.cpp` · `remove-nth-node-from-end-of-list-two-pointers.cpp` · `remove-nth-node-from-end-twopointers.cpp` · `reorder-list-middle-reverse-merge.cpp` · `split-linked-list-in-parts.cpp` · `swap-nodes-in-pairs.cpp`

### Maths

**Easy (2)**
- `palindrome-number-reversal.cpp` · `sqrtx-binary-search.cpp`

**Medium (1)**
- `reverse-integer-overflowcheck.cpp`

### Stack

**Easy (1)**
- `valid-parentheses-stack.cpp`

**Medium (1)**
- `removing-stars-from-a-string-stack.cpp`

### Strings

**Easy (5)**
- `find-first-occurrence-stl.cpp` · `find-the-index-of-the-first-occurrence-in-a-string-stl.cpp` · `first-unique-character-in-a-string-hash-map.cpp` · `reverse-string-two-pointers.cpp` · `valid-anagram-hashmap.cpp`

**Medium (3)**
- `longest-repeating-character-replacement-sliding-window.cpp` · `longest-substring-without-repeating-characters-sliding-window.cpp` · `maximum-number-of-vowels-in-a-substring-of-given-length-sliding-window.cpp`
<!-- AUTO-LEETCODE:END -->

> List is auto-generated from `leetcode/` by `scripts/update-readme-stats.py`
> (runs on every commit via the pre-commit hook on laptop, and on every
> push to `main` via the `Refresh README` GitHub Action). Don't edit the
> list above by hand — it gets overwritten.

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
