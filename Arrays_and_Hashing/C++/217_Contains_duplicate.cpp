/*
* TIME COMPLEXITY - O(nlogn)
* RUNTIME: 91 ms - Beats 99.47% of submissions
* MEMORY - 57.1 MB - Beats 100% of submissions
*/

#include <vector>
#include <algorithm>
#include <iostream>

/*
* Thoughtprocess:
* If the Array is empty or has only one element, return false
* Sort the array
* Iterate through the array and check if the current element is equal to the next element
*/
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        if (nums.size() <= 1)
            return false;
        sort(nums.begin(), nums.end());
        int check =nums[1];

        for (int num : nums)
        {
            if (check == num)
                return true;
            else
                check = num;
        }
        return false;
    }
};