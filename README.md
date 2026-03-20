# Day 04 - Two Pointers (Trapping Rain Water)

📌 What I Learned

Today I learned how to solve the **Trapping Rain Water** problem using the **two-pointer approach**.

Instead of using extra space, this method efficiently calculates trapped water by moving two pointers from both ends.

---

🔑 Key Concepts

- Two Pointers → Start from both ends (i, j)
- leftMax → Maximum height from left side
- rightMax → Maximum height from right side
- Water Calculation → min(leftMax, rightMax) - height[i]

---

💡 Approach

- Initialize two pointers (i = 0, j = n-1)
- Track leftMax and rightMax
- Move the pointer with smaller max value
- Calculate trapped water at each step

---

💻 Problem Implemented

- Trapping Rain Water (Optimized using Two Pointers)

---

⏱️ Complexity

- Time Complexity → O(n)
- Space Complexity → O(1)

---

🚀 Note

Understanding this problem improved my thinking in optimizing solutions from brute force to efficient approaches.

Practicing both **DSA + Development** side by side.
