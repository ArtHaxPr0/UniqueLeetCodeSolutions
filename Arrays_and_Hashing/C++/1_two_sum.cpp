
/*
* RUNTIME: 378 ms - Beats 14.88% of submissions
* MEMORY - 10.1 MB - Beats 99.97% of submissions
*/

#include <vector>
using namespace std;


/* Thoughtprocess:
* 1. Iterate through the array
* 2. For each element, iterate through the rest of the array and check if the sum of the current element and the next element is equal to the target
* 
* This could probaly be solved faster with a hash table 
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> yolo;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i+1; j < nums.size(); j++)
            {
                if ((nums[i]+nums[j]) == target)
                {
                    yolo.push_back(i);
                    yolo.push_back(j);
                    return yolo;
                }
            }
        }
        return yolo;
    }
};