/*
* RUNTIME: 39 ms - Beats 23.18% of submissions
* MEMORY - 21.3 MB - Beats 28.90% of submissions
*/

#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


/* Thoughtprocess:
*  1. Create a map of sorted strings to a vector of strings
*  2. Iterate through the input vector and sort each string
*  3. Add the sorted string to the map and push the original string to the vector
*  4. Iterate through the map and push the vectors to the result vector
* second indicates the element of the strings vector
*/


class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            map<string, vector<string>> anagrams;
            vector<vector<string>> result;
            for (string s : strs)
            {
                string sorted = s;
                sort(sorted.begin(), sorted.end());
                anagrams[sorted].push_back(s);
            }
            for (auto idx : anagrams)
            {
                result.push_back(idx.second);
            }
            return result;
        }
};

