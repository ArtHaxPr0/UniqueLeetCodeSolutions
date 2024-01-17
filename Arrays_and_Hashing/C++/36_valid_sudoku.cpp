/*
 * RUNTIME: 22 ms - Beats 38.46% of submissions
 * MEMORY - 19.53 MB - Beats 53.09% of submissions
 */

#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/* Thoughtprocess:
 *  1. Create enum for better readability and avoid three different maps
 *  2. Check vor Validy of Sudoku for rows and columns
 *  3. Check Validy of Sudoku for subboxes
 *  4. If Program reaches end of function, Sudoku is valid
 */

class Solution
{
public:

    enum sudokuConditions // Avoid Magic Numbers
    {
        row = 0,
        column = 1,
        subBox = 2
    };

    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<char, int> validyCondition[3]; 

        for (int i = 0; i < 9; i++)
        {
            validyCondition[row].clear();
            validyCondition[column].clear();
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    validyCondition[row][board[i][j]]++;
                }
                if (board[j][i] != '.')
                {
                    validyCondition[column][board[j][i]]++;
                }

                //Check Condition every iteration
                if (validyCondition[row][board[i][j]] > 1)
                    return false;
                if (validyCondition[column][board[j][i]] > 1)
                    return false;
            }
        }

        //Create for Loop to define Box
        for (int i = 0; i < 9; i += 3)
            for (int j = 0; j < 9; j += 3)
            {
                validyCondition[subBox].clear();
                //Create for Loop to check SubBox
                for (int x = i; x < i + 3; x++)
                    for (int y = j; y < j + 3; y++)
                    {
                        if (board[x][y] != '.')
                            validyCondition[subBox][board[x][y]]++;
                        if (validyCondition[subBox][board[x][y]] > 1)
                            return false;
                    }
            }
        return true;
    }
};
