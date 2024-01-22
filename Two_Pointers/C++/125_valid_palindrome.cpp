/*
* RUNTIME: 6 ms - Beats 48.89% of submissions
* MEMORY - 9.31 MB - Beats 5.55% of submissions
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;


/* Thoughtprocess:
* 1. Check if Char is alphanumeric
* 2. Convert Char to lowercase and store in seperate string
* 3. Reverse string
* 4. Compare strings
* 
* This could probaly be solved faster with starting from the middle and move left and right
*/


class Solution {
public:
    bool isPalindrome(string s) {

        string clearedStr = "";
        for (char c : s)
        {
            if ( (c >64 && c < 91) || (c > 96 && c < 123) || (c > 47 && c < 58))
            {
                clearedStr += tolower(c);
            }

        }
        string reversed = clearedStr;
        reverse(reversed.begin(), reversed.end());
        
        return clearedStr == reversed;

    }
};
