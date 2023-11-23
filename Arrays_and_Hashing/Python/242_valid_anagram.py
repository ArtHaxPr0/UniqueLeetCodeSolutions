
# RUNTIME: 55 ms, faster than 52.68% of python3 submissions. 
# MEMORY USAGE: 17.5 MB, Beats 6.75% of python3 submissions.

# My thougtprocess:
# 1. Sort both lists
# 2. Compare if the lists are equal

# This could probably be optimized further by using a dictionary to store counts.
# The Counter class from collections module could be used for this purpose.

# Time complexity: O(nlogn)

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        xs = sorted(s)
        xt = sorted(t)
        return xs == xt