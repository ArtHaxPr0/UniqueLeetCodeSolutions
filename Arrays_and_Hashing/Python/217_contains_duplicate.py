

# My thougtprocess:
# 1. Sort the array
# 2. Iterate through the array and check if the current element is equal to the previous element
# 3. If yes, return True

# Time complexity: O(nlogn)
# At fist I thought about using two loops, but that would have been O(n^2) time complexity
# Sorting seemed like a good idea, even though it could be probably optimized further. 

# RUNTIME: 507 ms, faster than 13.18% of python3 Submissions. 
# MEMORY USAGE: 28.2 MB, less than 95.25% of python3 Submissions.


from __future__ import annotations
from ast import *

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums.sort()
        for index, num in enumerate(nums):
            if index == 0:
                continue
            else:
                if nums[index-1] == num:
                    return True