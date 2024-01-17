# RUNTIME: 368 ms, faster than 79.01% of python3 Submissions. 
# MEMORY USAGE: 30.78 MB, less than 97.57% of python3 Submissions.

from __future__ import annotations
from ast import *


# My thougtprocess:
# 1. If the list is empty then return 0
# 2. Sort the list
# 3. Define first element as first element of the list
# 4. if the current element is equal to the previous element + 1 then increment the counter
# 5. if the current element is equal to the previous element then pass
# 6. if the current element is greater to the previous element+1 then check if the counter is greater than the max counter
# 7. assign new values
# 8. return the max counter



class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        nums.sort()
        y = 1
        a = nums[0]
        z = 0
        for num in nums:
            if num == a+1:
                y += 1
            elif num == a:
                pass
            else:
                if z < y:
                    z = y
                y = 1
            a = num
        if z > y:
            return z
        else:    
            return y