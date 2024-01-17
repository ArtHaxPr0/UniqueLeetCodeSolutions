# RUNTIME: 116 ms, faster than 15.14% of python3 Submissions.
# MEMORY USAGE: 16.55 MB, less than 52.29% of python3 Submissions.

from __future__ import annotations
from ast import *
from collections import Counter


# My thougtprocess:
# 1. Check store numeric values in a list for Columns and Rows
# 2. Check store numeric values in a list for sub-boxes
# 3. Check if the list is empty then it is a valid sudoku
# 4. Check if the most common element in the list is greater than 1 then it is not a valid sudoku
# 5. Else it is a valid sudoku

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        s = []
        c = ""
        c2 = ""

        # check rows and columns
        for i in range(9):
            c = ""
            for j in range(9):
                #check rows
                if board[i][j] == ".":
                    pass
                else:
                    c += str(board[i][j])
                #check columns
                if board[j][i]  == ".":
                    pass
                else:
                    c2 += str(board[j][i])
                    
            s.append(list(c))
            s.append(list(c2))

        # check sub-boxes
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                c = ""
                for k in range(3):
                    for l in range(3):
                        if board[i + k][j + l] == ".":
                            pass
                        else:
                            c += str(board[i + k][j + l])
                s.append(list(c))

        # if list is empty then it is a valid sudoku
        if s.count([]) == 27:
            return True

        # if most common is greater than 1 then it is not a valid sudoku
        for x in s:
            if x == []:
                continue
            cnt = Counter(x)
            if cnt.most_common(1)[0][1] > 1:
                return False

        return True
