/*
* RUNTIME: 7 ms - Beats 93.57% of submissions
* MEMORY - 22.20 MB - Beats 6.36% of submissions
*/

#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;


/* Thoughtprocess:
* 1. initailize a left and right pointer
* 2. int max left and max right
* 3. initiate while loop while left < right
* 4. evaluate the new max values
* 5. if max_left is less than max_right, add the difference between max_left and height[left] to maxArea
* 6. else add the difference between max_right and height[right] to maxArea
* 7. Depending on the higher value decrease/increase the left/right pointer
* 8. Return the maximum area
* 
*/







class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_left = 0, max_right = 0;
        int maxArea = 0;

        while (left < right)
        {
            max_left = max(max_left, height[left]);
            max_right = max(max_right, height[right]);
            if (max_left < max_right)
            {
                maxArea += max_left - height[left];
                left++;
            }
            else
            {
                maxArea += max_right - height[right];
                right--;
            }
        } 
        return maxArea;
    }
};
