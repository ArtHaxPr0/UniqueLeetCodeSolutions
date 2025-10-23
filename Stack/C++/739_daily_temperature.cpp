/*
* RUNTIME: 37 ms - Beats 12.28% of C++ submissions
* MEMORY - 112.00 MB - Beats 05.03% of submissions
*/

#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <unordered_map>
#include <functional>
using namespace std;


// My thought process:
//
// 1. Initialize a result vector with the same length as `temperatures` and set all elements to 0.
// 2. Initialize a stack that stores pairs of (temperature, index).
// 3. Loop through the `temperatures` array using an index variable to track both day and temperature.
// 4. While the stack is not empty and the current temperature is higher than the top element’s temperature:
//      - Pop the last element from the stack.
// 5. Calculate the number of days it took to reach a higher temperature:
//      - result[previous_index] = current_day - previous_index;
// 6. If the current temperature is not higher, push (temperature, index) onto the stack and continue.
// 7. After iterating through all temperatures, return the result vector.


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> st;

        for (int curr_day = 0; curr_day < n; ++curr_day)
        {
            int temp = temperatures[curr_day];
            while (!st.empty() && temp > st.top().first)
            {
                int prev_temp = st.top().first;
                int prev_day = st.top().second;
                st.pop();
                res[prev_day] = curr_day - prev_day;
            }
            st.push({temp, curr_day});
        }

        return res;
    }
};