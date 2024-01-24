/*
* RUNTIME: 66 ms - Beats 75.96% of submissions
* MEMORY - 61.50 MB - Beats 5.99% of submissions
*/

#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;


/* Thoughtprocess:
* 1. initailize a left and right pointer
* 2. Comapare the maximum area with the current area
* 3. If left height is less than right height, move the left pointer to the right
* 4. If right height is less than left height, move the right pointer to the left
* 5. Repeat untill no possibilities are left
* 6. Return the maximum area
* 
*/


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int area = 0;

        while (left < right)
        {
            area = max(area, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return area;
    }
};