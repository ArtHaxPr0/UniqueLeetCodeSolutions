/*
* RUNTIME: 0 ms - Beats 100.00% of submissions
* MEMORY - 97.46 MB - Beats 25.75% of submissions
*/

#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;


/* Thoughtprocess:
* 1. Initialize two pointers, left and right.
* 2. left pointer tracks the minimum price so far.
* 3. right pointer iterates through each price in the list.
* 4. If the current price (right) is greater than left, calculate potential profit.
* 5. Update maxValue if the calculated profit is higher than the current maxValue.
* 6. If the current price (right) is less than left, update left to the current price.
* 7. Continue until all prices are processed.
* 8. Return maxValue as the maximum profit achievable.
* 
*/

// Time Complexity: O(n) - single pass through prices
// Space Complexity: O(1) - only a few extra variables used

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = prices[0];
        int right = 0;
        int maxValue = 0;

        for (auto current_price : prices)
        {
            right = current_price;
            if (right > left)
            {
                if (maxValue < right - left)
                {
                    maxValue = right - left;
                }
            }
            else if (right < left)
            {
                left = right;
            }
        }
        return maxValue;
    }
};