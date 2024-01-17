/*
* RUNTIME: 67 ms - Beats 95.12% of submissions
* MEMORY - 45.97 MB - Beats 96.84% of submissions
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
* Thoughtprocess:
* 1. If the Vector is empty or has one or less element, size
* 2. Sort the Vector
* 3. Iterate through the Vector and check if the current element is equal to the next element
* 4. If the current element is equal to the next element, continue next iteration
* 5. If the current element is not equal to the next element, check if the current element+1 is equal to the next element
* 6. If the current element+1 is equal to the next element, increase current counter
* 7. If the current element+1 is not equal to the next element, check if the current counter is greater than the longest counter
* 8. Return the longest counter 
*/

vector<int> nums = {100,4,200,1,3,2};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.size() <= 1)
            return nums.size();
        sort(nums.begin(), nums.end());
        int longest = 0;
        int current = 1;
        int check = nums[0];

        for (auto num : nums)
        {
            if (check == num)
                continue;
            else if (check + 1 == num)
                current++;
            else
            {
                longest = max(longest, current);
                current = 1;
                
            }
            check = num;
        }


        return max(longest, current);
    }
};

int main()
{
    Solution solution;
    cout << solution.longestConsecutive(nums);
    return 0;
}