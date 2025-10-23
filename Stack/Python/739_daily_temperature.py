# RUNTIME: 121 ms, faster than 40.42% of python3 Submissions. 
# MEMORY USAGE: 33.80 MB, less than 16.81% of python3 Submissions.

from __future__ import annotations
from ast import *


# My thougtprocess:
# 1. Initiate a restultstack with len(temperature) elements and set all to "0"
# 2. Initaite a stack that contains a touple containing the temperature and the index
# 3. loop through as enumerate to get the index value aswell
# 4. while stack is available and new temperature is higher pop last stack element
# 5. input the days it took to get the higher value into resultstack
#   5.1 to get the amount of days take current day  - stack index (inital day)
# 6. if temperature is lower append to st and iterate through next for loop cycle
# 7. if all elements of "temperatures" are cycled return the result list


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0] * len(temperatures)
        st = []

        for curr_day, temp in enumerate(temperatures):
            while st and temp > st[-1][0]:
                _, st_ind = st.pop()
                res[st_ind] = curr_day - st_ind

            st.append((temp, curr_day))

        return res
    

ls  = [73,74,75,71,69,72,76,73] 
sol = Solution()
print (sol.dailyTemperatures(ls))