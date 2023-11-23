# RUNTIME: 92 ms, faster than 85.22% of python3 Submissions. 
# MEMORY USAGE: 19.6 MB, less than 76.26% of python3 Submissions.

from __future__ import annotations
from ast import *


# My thougtprocess:
# 1. Create a dictionary
# 2. Iterate through the list
# 3. Sort the current element
# 4. Check if the sorted element is in the dictionary
# 5. If yes, append the current element to the dictionary
# 6. If no, create a new key with the sorted element and append the current element to the dictionary
# 7. Return the values of the dictionary

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dict = {}
        ls = []
        for s in strs:
            sortedString = "".join(sorted(s))
            dict[sortedString] = dict.get(sortedString, []) +[s]
        for key in dict:
            ls.append(dict[key])
        return ls