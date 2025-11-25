# RUNTIME: 147 ms, faster than 79.83% of python3 Submissions. 
# MEMORY USAGE: 36.09 MB, less than 20.88% of python3 Submissions.

from __future__ import annotations
from ast import *

# My thought process:
# 1. Use a stack to store bars as pairs (start_index, height).
# 2. Iterate through each bar in heights.
# 3. If the current bar is lower than the bar on top of the stack, 
#    then the taller bar must end here, so calculate its area.
# 4. While popping, track the earliest start index for which the height applies.
# 5. Push the current bar with its correct start index onto the stack.
# 6. After processing all bars, remaining bars in the stack extend to the end of the histogram.
# 7. Compute maximal areas for all leftover bars.
# 8. Return the largest rectangle found.

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        maxArea = 0
        stack = []  # pair: (index, height)

        for i, h in enumerate(heights):
            start = i
            while stack and stack[-1][1] > h:
                index, height = stack.pop()
                maxArea = max(maxArea, height * (i - index))
                start = index
            stack.append((start, h))

        for i, h in stack:
            maxArea = max(maxArea, h * (len(heights) - i))

        return maxArea