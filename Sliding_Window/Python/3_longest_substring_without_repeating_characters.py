# RUNTIME: 158 ms, faster than 11.20% of python3 Submissions. 
# MEMORY USAGE: 17.78 MB, less than 81.82% of python3 Submissions.

from __future__ import annotations
from ast import *

# My first idea was to use a brute force approach with nested loops to check all substrings
# but that would have a time complexity of O(n^2). Instead, I decided to use the sliding window technique
# which allows us to maintain a window of unique characters and adjust its size dynamically.

# However, I recognize that this implementation is not optimal my solution has Time complexity of O(n^2)
# due to the nested loop checking for duplicates in the current window. I will elaborate on potential improvements
# after I have extended my knowledge of sliding window techniques and hash maps. In the next instance,
# I would like to focus on optimizing the current solution

# especially in terms of readability and maintainability. I am not satisfied with the current solution
# and would like to explore more efficient algorithms or data structures
# especially regarding the slow runtime.


# My thought process:
# 1. create a set to store unique characters
# 2. define left and right pointers to represent the current window
# 3. iterate through the string with the right pointer
# 4. for each character in the current window, check if it is already in the set
# 5. if it is, move the left pointer and break the loop to iterate again with the new window one further to the right
# Window looks like this:
# [x][][][][][][] -> left = 0, right = 2 [x][x] are part of the window
# [ ][x][x][][][][] -> left = 1, right = 3 [x][x] are part of the window
# [ ][ ][x][x][][][] -> left = 2, right = 4 [x][x] are part of the window
# 6. Windowsize dynamically changes as left and right pointers move
# 7. if no duplicate is found, add the character to the set
# 8. continue until the right pointer reaches the end of the string

# Time complexity is O(n*m) in the worst case O(n^2) due to the nested loop checking for duplicates in the current window
# Space complexity is O(min(m, n)) where m is the size of the character set


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        unique_chars = set()
        left = 0
        right = 1
        max_right = len(s) + 1

        if s == "":
            return 0
        
        while not right == max_right:
            window = s[left:right]

            for c in window:
                if c in unique_chars:
                    left = left +1
                    break
                else:
                    unique_chars.add(c)

            right = right + 1
            unique_chars.clear()
        size = len(s) - left

        return size