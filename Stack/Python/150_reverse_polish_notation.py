# RUNTIME: 3 ms, faster than 63.94% of python3 Submissions. 
# MEMORY USAGE: 19.06 MB, less than 87.91% of python3 Submissions.


# My thougtprocess:
# 1. Define a open stack
# 2. Define operations - what happens when "+" ist in list etc.
# 3. Check if character is in operation list
# 4. If not simply append
# 5. Else use predetermined operation with two right most values
# 6. If deviding need to cast int or we may get float value
# 7. Return remaining stack element.


import operator
from typing import List



tkns = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        ops = {
            "+": operator.add,
            "-": operator.sub,
            "*": operator.mul,
            "/": lambda left, right: int(left / right)
        }
        for c in tokens:
            if c not in ops:
                st.append(int(c))
            else:
                right = st.pop()
                left = st.pop()
                st.append(ops[c](left, right))
        return st[-1]





sol = Solution()
print(sol.evalRPN(tkns))  # 22
