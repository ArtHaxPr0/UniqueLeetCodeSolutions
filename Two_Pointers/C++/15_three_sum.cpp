/*
* RUNTIME: 786 ms - Beats 36.31% of submissions
* MEMORY - 190.52 MB - Beats 32.46% of submissions
*/

#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;


/* Thoughtprocess:
* 1. initailize a left and right pointer
* 2. create a set to store the unique triplets
* 3. Initiate a loop to iterate through the vector
* 4. Use two pointers to browse through the vector
* 5. If the sum of the three numbers is equal to the target, add the triplet to the set
* 6. If the sum is less than the target, move the left pointer to the right
* 7. If the sum is greater than the target, move the right pointer to the left
* 8. Repeat untill no possibilities are left
* 9. Return the set as a vector
* 
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        set <vector<int>> s;
        int left, right;
        int sum;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            left = i + 1;
            right = nums.size() - 1;
            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                if ( sum == target)
                {
                    s.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if (sum < target)
                    left++;
                else
                    right--;
            }
        }
        return vector<vector<int>> (s.begin(), s.end());
    }
};