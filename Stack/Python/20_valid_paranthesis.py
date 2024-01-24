# RUNTIME: 50 ms, faster than 11.56% of python3 Submissions. 
# MEMORY USAGE: 16.27 MB, less than 95.00% of python3 Submissions.

from __future__ import annotations
from ast import *


# My thougtprocess:
# 1. Define open and close list
# 2. Define stack
# 3. if first element is in close list, return False
# 4. if element is in open list, append to stack
# 5. if element is in close list, check if stack is empty, if yes return False
# 6. if stack is not empty, check if last element of stack is equal to the corresponding open list element
# 7. if yes, pop the last element of stack
# 8. if no, return False
# 9. if stack is empty, return True

class Solution:
    def isValid(self, s: str) -> bool:
        open_list = ["[", "{", "("]
        close_list = ["]", "}", ")"]
        stack = []
        if s[0] in close_list:
            return False
        for c in s:
            if c in open_list:
                stack.append(c)
            elif c in close_list:
                if len(stack) == 0:
                    return False
                elif stack[-1] == open_list[1] and c == close_list[1]:
                    stack = stack[:-1]
                elif stack[-1] == open_list[0] and c == close_list[0]:
                    stack = stack[:-1]
                elif stack[-1] == open_list[2] and c == close_list[2]:
                    stack = stack[:-1]
                else:
                    return False
        if len(stack) == 0:
            return True
        return False