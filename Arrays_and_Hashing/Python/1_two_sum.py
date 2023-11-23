# RUNTIME: 61 ms, faster than 81.10% of python3 Submissions. 
# MEMORY USAGE: 15.1 MB, less than 100% of python3 Submissions.

from __future__ import annotations
from ast import *


# My thougtprocess:
# 1. Create a dictionary with key = value and value = index
# 2. Iterate through the list
# 3. Calculate the difference between the target and the current element
# 4. Check if the difference is in the dictionary
# 5. If yes, return the indices of the current element and the difference

# Time complexity: O(n)
# At fist I thought about using two loops, but that would have been O(n^2) time complexity
# As Learining from the c++ sultion I used a dictionary to store the values and indices

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        prevMap = {} # val : index
        
        for i, n in enumerate(nums):
            diff = target - n
            if diff in prevMap:
                return [prevMap[diff], i]
            prevMap[n] = i