# RUNTIME: 4 ms, faster than 71.82% of python3 Submissions. 
# MEMORY USAGE: 21.19 MB, less than 97.94% of python3 Submissions.


# My thougtprocess:
# 1. Define two lists - one stack - one min value
# 2. if stack is empty append min value
# 3. else append only to minValue if last min is less
# 4. pop stack from both lists if equal
# 5. return latest element in called lists


class MinStack:


    def __init__(self):
        self.stack = []
        self.minVal = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        if (not self.minVal):
            self.minVal.append(val)
        elif (val <= self.minVal[-1]):
            self.minVal.append(val)

    def pop(self) -> None:
        if (self.stack[-1] == self.minVal[-1]):
            self.minVal = self.minVal[:-1]
        self.stack = self.stack[:-1]

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minVal[-1]

