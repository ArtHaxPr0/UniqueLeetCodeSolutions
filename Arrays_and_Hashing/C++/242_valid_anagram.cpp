
/*
* TIME COMPLEXITY - O(nlogn)
* RUNTIME: 9 ms - Beats 55.70% of submissions
* MEMORY - 7.4 MB - Beats 99.91% of submissions
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
/*
* Thoughtprocess:
* 1. Sort both strings
* 2. Compare the strings
*/

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
