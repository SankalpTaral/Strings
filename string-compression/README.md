# 🧵 String Compression

### ✅ Problem Statement:
You are given an array of characters `s`. Use in-place compression to replace consecutive repeating characters with the character followed by the count of repetitions.

Return the new length of the compressed array.

Compression Rule:
- For a group of repeating characters like `["a","a","a"]`, compress it as `["a","3"]`.
- If a character appears once, do not add a number (e.g., `["b"] → ["b"]`).

---

### 🧠 Intuition:

Instead of using extra space, we can use **two pointers**:

- `index`: points to where the next compressed character or count should be written.
- `prev`: keeps track of the previous character group.
- `count`: counts the current group size.

Whenever a mismatch is found, write `prev` at `index`, and if `count > 1`, convert the count into string digits and insert them character by character.

---

### ⚙️ Algorithm:

1. Initialize:
   - `prev = s[0]`
   - `count = 1`
   - `index = 0`

2. Traverse from `i = 1` to `s.size() - 1`:
   - If `s[i] == prev`, increment `count`.
   - Else:
     - Write `prev` at `s[index++]`.
     - If `count > 1`, convert count to string using `intToStr(count)` and write each digit.
     - Reset `prev = s[i]`, `count = 1`.

3. After loop ends, handle the last group similarly.

4. Return `index` as the new length.

---

### 💻 Code (C++)

```cpp
class Solution {
public:
    string intToStr(int num) {
        if (num == 0) return "0";
        string result = "";
        while (num > 0) {
            int digit = num % 10;
            char ch = '0' + digit;
            result = ch + result;  // Prepend to reverse the string
            num = num / 10;
        }
        return result;
    }

    int compress(vector<char>& s) {
        int index = 0;
        int count = 1;
        char prev = s[0];

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == prev) {
                count++;
            } else {
                s[index++] = prev;
                if (count > 1) {
                    for (char c : intToStr(count)) {
                        s[index++] = c;
                    }
                }
                prev = s[i];
                count = 1;
            }
        }

        // Handle last group
        s[index++] = prev;
        if (count > 1) {
            for (char c : intToStr(count)) {
                s[index++] = c;
            }
        }

        return index;
    }
};
