/*
* RUNTIME: 9 ms - Beats 65.33% of submissions
* MEMORY - 17.96 MB - Beats 5.28% of submissions
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;


/* Thoughtprocess:
* 1. Initiate two pointers, one at the left and one on the right
* 2. While left < right, check if the sum of the two pointers is equal to the target
* 3. If the sum is less than the target, move the left pointer to the right
* 4. If the sum is greater than the target, move the right pointer to the left
* 
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        vector<int> result;
        while (left < right)
        {
            if (numbers[left] + numbers[right] == target)
            {
                result.push_back(left+1);
                result.push_back(right+1);
                return result;
            }
            else if (numbers[left] + numbers[right] < target)
                left++;
            else
                right--;
        }
        return result;
    }
};
