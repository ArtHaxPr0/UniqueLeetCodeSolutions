# RUNTIME: 202 ms, faster than 43.84% of python3 Submissions. 
# MEMORY USAGE: 39.55 MB, less than 59.23% of python3 Submissions.

from __future__ import annotations
from ast import *

# My thougtprocess:
# 1. create touple pairing position and assigned speed
# 2. reverse sort the touple to start a stack from the closest targetposition
# 3. create empty stack
# 4. iterate through the touple
# 5. append stepcount needed to reach the target into the stack
# 6. if following position is faster than the last they will eventually meet. This results in a fleet
# 7. Therefore pop the last element and check the next
# 8. Otherwise this counts as "unique"-fleet.
# 9. The next position following a new fleet checks the top position of the fleet.
# 10.Return the length of the stack to get the amount of Fleets





class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        #sorting following array means O(log n)
        linear_pair = [(pos, sp) for pos, sp in zip(position, speed)] #create a touple for easier processing and sorting later on
        linear_pair.sort(reverse=True) # sort reversed to start with the car closest to the target
        stack = []

        for pos, sp in linear_pair: #iteration through n-entries results in O(n)
            steps = ((target - pos) / sp) #less steps means faster car
            stack.append(steps)
            if len(stack) >= 2:
                if stack[-1] <= stack[-2]:
                    stack.pop()
        return len(stack) #Answer should have time complexity O(n log n)
    