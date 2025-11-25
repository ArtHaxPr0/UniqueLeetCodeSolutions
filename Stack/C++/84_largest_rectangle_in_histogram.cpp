/*
* RUNTIME: 11 ms - Beats 94.17% of C++ submissions
* MEMORY - 88.21 MB - Beats 14.85% of submissions
*/


#include <vector>
#include <algorithm>
using namespace std;


/*
My thought process:
1. Use a stack to store bars as pairs (start_index, height).
2. Iterate through each bar in heights.
3. If the current bar is lower than the bar on top of the stack,
    then the taller bar must end here, so calculate its area.
4. While popping, track the earliest start index for which the height applies.
5. Push the current bar with its correct start index onto the stack.
6. After processing all bars, remaining bars in the stack extend to the end of the histogram.
7. Compute maximal areas for all leftover bars.
8. Return the largest rectangle found.
*/

class Solution {
    public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        vector<pair<int, int>> stack; // pair: (start index, height)

        for (int i = 0; i < heights.size(); i++) {
            int h = heights[i];
            int start = i;

            // While current height is lower, resolve taller bars
            while (!stack.empty() && stack.back().second > h) {
                auto [index, height] = stack.back();
                stack.pop_back();
                maxArea = max(maxArea, height * (i - index));
                start = index;  // earliest index this height can span
            }

            stack.emplace_back(start, h);
        }

        // Remaining bars extend to the end
        for (auto& p : stack) {
            int index = p.first;
            int height = p.second;
            maxArea = max(maxArea, height * ((int)heights.size() - index));
        }

        return maxArea;
    }
};