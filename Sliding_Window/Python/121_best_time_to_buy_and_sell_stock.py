# RUNTIME: 25 ms, faster than 89.55% of python3 Submissions. 
# MEMORY USAGE: 26.95 MB, less than 32.87% of python3 Submissions.

from __future__ import annotations
from ast import *

# My thought process:
# 1. assign right pointer to 0 and left pointer to first element
# 2. assign maxVal to 0
# 3. iterate through prices
# 4. right pointer gets current price
# 5. if value at right pointer is higher than left pointer check if maxVal needs to be updated
# 6. otherweise if right pointer is lower than left pointer update left pointer to right value
# 7. continue until all prices are processed
# 8. Return maxVal (if no profit possible this will be 0 as initialized)


# Time complexity is O(n) as we only iterate once through the prices list
# Space complexity is O(1) as no additional data structures dependent on input size are used
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        right = 0
        left = prices[0]
        maxVal = 0
        
        for current_price in prices:
            right = current_price
            if (right > left):
                if (maxVal < right - left):
                    maxVal = right - left
            elif (right < left):
                left = right

        return maxVal
                