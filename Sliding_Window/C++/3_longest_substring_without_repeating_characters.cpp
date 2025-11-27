/*
    This C++ implementation is a direct translation of the provided Python code.

    The algorithm uses a sliding-window-like technique, but it is not fully optimized.
    It still runs in O(n^2) time because:
        - For every window expansion, the code rebuilds the window substring.
        - It iterates through all characters in the window to check for duplicates.
        - The set of unique characters is cleared each loop, losing previous work.

    Thought process behind the algorithm (mirroring original Python explanation):
    1. Maintain a set to track unique characters inside the window.
    2. Use left and right pointers to define a substring window.
    3. Move the right pointer step-by-step through the string.
    4. For each new window, check all characters for duplicates.
    5. If a duplicate is found, move the left pointer forward and rebuild the window next iteration.
    6. Window size changes dynamically as left and right move.
    7. Continue until the right pointer passes the end of the string.
    8. Final window size = string length minus left pointer.

    Complexity:
      - Time:  O(n^2)
      - Space: O(min(n, charset_size))

*/

#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        std::unordered_set<char> unique_chars;
        int left = 0;
        int right = 1;
        int max_right = static_cast<int>(s.size()) + 1;

        if (s.empty()) {
            return 0;
        }

        while (right != max_right) {
            std::string window = s.substr(left, right - left);

            for (char c : window) {
                if (unique_chars.count(c)) {
                    left++;
                    break;
                } else {
                    unique_chars.insert(c);
                }
            }

            right++;
            unique_chars.clear();
        }

        return static_cast<int>(s.size()) - left;
    }
};