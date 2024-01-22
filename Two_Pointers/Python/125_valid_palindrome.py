# RUNTIME: 485 ms, faster than 5.17% of python3 Submissions. 
# MEMORY USAGE: 17.19 MB, less than 84.44% of python3 Submissions.

from __future__ import annotations
from ast import *


# My thougtprocess:
# 1. Convert the string to lowercase
# 2. Remove all non-alphanumeric characters
# 3. Reverse the string
# 4. Compare the reversed string to the original string


class Solution:
    def isPalindrome(self, s: str) -> bool:
        def replaceAll(input):
            for c in input:
                if c in " ,.!?:;-_()[]{}\/|<>\#$%&=+*~^`@'\"":
                    input = input.replace(c, "")
            return input
        cropped_string = s.lower()
        cropped_string = replaceAll(cropped_string)
        reversed_string = cropped_string[::-1]
        return cropped_string == reversed_string