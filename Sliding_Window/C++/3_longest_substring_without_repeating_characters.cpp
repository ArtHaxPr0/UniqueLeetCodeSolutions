
/* Thoughtprocess:
* 1. Maintain a set to track unique characters inside the window.
* 2. Use left and right pointers to define a substring window.
* 3. Move the right pointer step-by-step through the string.
* 4. For each new window, check all characters for duplicates.
* 5. If a duplicate is found, move the left pointer forward and rebuild the window
*    next iteration.
* 6. Window size changes dynamically as left and right move.
* 7. Continue until the right pointer passes the end of the string.
* 8. Final window size = string length minus left pointer.
*/


#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> unique_chars;
        int left = 0;
        int right = 1;
        int max_right = static_cast<int>(s.size()) + 1;

        if (s.empty()) {
            return 0;
        }

        while (right != max_right) {
            string window = s.substr(left, right - left);

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