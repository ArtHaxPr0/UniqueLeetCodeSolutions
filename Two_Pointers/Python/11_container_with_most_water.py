# RUNTIME: 532 ms, faster than 78.47% of python3 Submissions. 
# MEMORY USAGE: 29.47 MB, less than 63.59% of python3 Submissions.

from __future__ import annotations
from ast import *


# My thougtprocess:
# 1. Define left and right pointers
# 2. check the maximum area between left and right and update maxArea
# 3. if sum of left height is smaller than right height, we need to increase left
# 4. return the max area
height = [1,8,6,2,5,4,8,3,7]

class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        maxArea = 0

        while left < right:
            maxArea = max(maxArea, min(height[left], height[right]) * (right - left))

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return maxArea