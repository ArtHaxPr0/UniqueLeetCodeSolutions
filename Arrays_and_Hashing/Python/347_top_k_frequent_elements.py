# RUNTIME: 93 ms, faster than 84.22% of python3 submissions. 
# MEMORY USAGE: 21.0 MB, Beats 73.64% of python3 submissions.

from __future__ import annotations
from ast import *
from collections import Counter

# My thougtprocess:
# 1. Create a list where the Counter class tracks which are numbers are used the most.

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        xs = [num for num,cnt in Counter(nums).most_common(k)]
        return xs