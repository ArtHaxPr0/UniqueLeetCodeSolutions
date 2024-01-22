# RUNTIME: 99 ms, faster than 95.50% of python3 Submissions. 
# MEMORY USAGE: 17.38 MB, less than 65.45% of python3 Submissions.

from __future__ import annotations
from ast import *


# My thougtprocess:
# 1. Set left and right borders
# 2. if sum of left and right is equal we have the suolution
# 3. if sum of left and right is less than target, we need to increase left
# 4. if sum of left and right is greater than target, we need to decrease right
# 5. continue until solution is found or left is greater than right
# 6. Because there is a solution, we don´t need the last return, but it is good to have it




class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1
        
        while left < right:
            if numbers[left] + numbers[right] == target:
                return [left + 1, right + 1]
            elif numbers[left] + numbers[right] < target:
                left += 1
            else:
                right -= 1
        return [-1, -1]