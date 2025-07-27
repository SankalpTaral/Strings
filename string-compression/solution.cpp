#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string intToStr(int num) {
        if (num == 0) return "0";
        string result = "";
        while (num > 0) {
            int digit = num % 10;
            char ch = '0' + digit;
            result = ch + result;
            num /= 10;
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

        s[index++] = prev;
        if (count > 1) {
            for (char c : intToStr(count)) {
                s[index++] = c;
            }
        }

        return index;
    }
};
