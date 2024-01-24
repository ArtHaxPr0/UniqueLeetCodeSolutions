# RUNTIME: 101 ms, faster than 80.77% of python3 Submissions. 
# MEMORY USAGE: 18.52 MB, less than 65.02% of python3 Submissions.

from __future__ import annotations
from ast import *


# My thougtprocess:
# 1. Especially after doing the C++ Version I recognize that this could be done more efficiently
# 2. Nonetheless, I want to present my first Bare bones solution that fitted the problem

# 1. initiale left, right, max values and a check
# 2. Checks Purpsose is to not include left and right borders, as the water could not be trapped there
# 3. if left height is smaller than right height, we need to increase left
# 4. return the max area as in the previous two pointer solutions

class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) == 1:
            return 0
        left, right = 0, len(height) - 1
        max_left, max_right = 0, 0
        maxArea = 0
        c = 0
        c2 = 0

        while left < right:
            if height[left] <= c2:
                c2 = height[left]
                left += 1
            else:
                c = 1
        c2 = height[right]
        
        while c == 1 and left < right:
            if height[right] >= c2:
                c2 = height[right]
                right -= 1
            else:
                c = 0
                right += 1
        
        while left < right:
            max_left = max(max_left, height[left])
            max_right = max(max_right, height[right])
            if max_left < max_right:
                maxArea += max_left - height[left]
                left += 1
            else:
                maxArea += max_right - height[right]
                right -= 1
        return maxArea
