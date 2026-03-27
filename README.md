## 🔁 Recursion

### Problems Implemented
- print 1 to n numbers using recursion
- Reverse an array using recursion  
- check palindrome using recursion
- binary search using recursion
- Find power of a number using recursion
---

### 📌 Reverse Array (Recursion)

**Approach:**
- Swap first and last elements  
- Recursively solve for remaining array  

**Base Case:**
- Stop when start >= end  

**Complexity:**
- Time: O(n)  
- Space: O(n) (recursion stack)

### 📌 Palindrome Check (Recursion)

**Approach:**
- Compare first and last elements  
- Recursively check inner elements  

**Base Case:**
- start >= end → palindrome  

**Complexity:**
- Time: O(n)  
- Space: O(n)
### 📌 Binary Search (Recursion)

**Approach:**
- Divide array into two halves  
- Compare middle element with key  
- Recursively search left or right  

**Condition:**
- Array must be sorted  

**Complexity:**
- Time: O(log n)  
- Space: O(log n)
  
  ### 📌 Power of a Number (Recursion)

**Approach:**
- Multiply x with recursive result of (x, n-1)

**Base Case:**
- n == 0 → return 1  

**Complexity:**
- Time: O(n)  
- Space: O(n)
