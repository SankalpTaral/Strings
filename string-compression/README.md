# String Compression

### 🔍 Problem
Given an array of characters, compress it **in-place** and return the new length of the array.

### 💡 Approach
- Track `prev` and `count` as you iterate.
- If count > 1, convert it to string and insert digit-wise using a helper.
- Update the array in-place using an index pointer.

### ✅ Time Complexity
O(N + logK) where N = size of array, K = max group count

### ✍️ Code
See `solution.cpp`
