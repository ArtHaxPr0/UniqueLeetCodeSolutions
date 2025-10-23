# RUNTIME: 0 ms, faster than 100% of python3 Submissions. 
# MEMORY USAGE: 17.96 MB, less than 69.94% of python3 Submissions.

from __future__ import annotations
from ast import *

# My thougtprocess:
# 1. define "empty" stack
# 2. define result list
# 3. loop through while stack is not empty
# 4. generate the parenthesis
# 5. continue until all possible combinations are done

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:

 
        stack = [("", 0, 0)]
        result = []

        while len(stack) > 0:
            s, opened, closed = stack[-1]
            stack = stack[:-1]

            if opened == n and closed == n:
                result.append(s)
                continue

            if closed < opened:
                stack.append((s + ")", opened, closed + 1))

            if opened < n:
                stack.append((s + "(", opened + 1, closed))

        return result
