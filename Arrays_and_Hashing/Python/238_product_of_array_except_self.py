# RUNTIME: 194 ms, faster than 60.38% of python3 Submissions. 
# MEMORY USAGE: 25.5 MB, less than 12.52% of python3 Submissions.

from __future__ import annotations
from ast import *


# My thougtprocess:
# 1. Get length of the list
# 2. initiate three lists containing 1s with equal length
# 3. interate through the list and calculate the left products and then the right side
# 4. interate through the list and calculate the result

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left_products = [1] * n
        right_products = [1] * n
        result = [1] * n
        
        left_product = 1
        for i in range(n):
            left_products[i] = left_product
            left_product *= nums[i]
        
        right_product = 1
        for i in range(n - 1, -1, -1):
            right_products[i] = right_product
            right_product *= nums[i]
        
        for i in range(n):
            result[i] = left_products[i] * right_products[i]
        
        return result