# RUNTIME: 1298 ms, faster than 33.25% of python3 Submissions. 
# MEMORY USAGE: 20.02 MB, less than 99.45% of python3 Submissions.

from __future__ import annotations
from ast import *


# My thougtprocess:
# 1. Define Target as 0
# 2. Set left to i + 1 and right to len(nums) - 1
# 3. if sum of left and right is less than target, we need to increase left
# 4. if sum of left and right is greater than target, we need to decrease right
# 5. continue until solution is found or left is greater than right

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        target = 0
        nums.sort()
        output = set()
        result = []
        for i in range(len(nums)):
            left = i + 1
            right = len(nums) - 1
            while left < right:
                sum = nums[i] + nums[left] + nums[right]
                if sum == target:
                    output.add((nums[i], nums[left], nums[right]))
                    left += 1
                    right -= 1
                elif sum < target:
                    left += 1
                else:
                    right -= 1
        result = list(output)
        return result
