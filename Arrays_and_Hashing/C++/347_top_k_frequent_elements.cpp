
/*
* RUNTIME: 10 ms - Beats 80.67% of submissions
* MEMORY - 14.3 MB - Beats 23.79% of submissions
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;
/*
* Thoughtprocess:
* 1. Count the amount of apearances for each int
* 2. create a set and swap the first value with the second
* 3. reverse the set to descend values
* 4. fill the resultvector with the top k values
*/

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> counter;
            set<pair<int, int>> set;

            for (int num : nums)
            {
                counter[num]++;
            }
            for (auto kv : counter)
            {
                set.emplace(kv.second, kv.first);
            }
            vector<int> result;
            auto it = set.rbegin();
            for (int i = 0; i < k; ++i, ++it) {
                result.push_back(it->second);
            }
            return result;
        }
};