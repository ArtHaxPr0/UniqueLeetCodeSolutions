/*
* RUNTIME: 19 ms - Beats 54.04% of submissions
* MEMORY - 26.57 MB - Beats 5.25% of submissions
*/

#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


/* Thoughtprocess:
*  1. store the size of the input vector
*  2. initiate three vectors of size n: left, right and result
*  3. calculate the product of all elemeents without the first element and store it in left
*  4. calculate the product of all elemeents without the last element and store it in right
*  5. multiply the elements of left and right and store it in result
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        vector<int> left(n, 1);
        vector<int> right(n, 1);

        int product = 1;
        for (int i = 0; i < n; i++)
        {
            left[i] = product;
            product *= nums[i];
        }
        product = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            right[i] = product;
            product *= nums[i];
        }
        for (int i = 0; i < n; i++)
        {
            result.push_back(left[i] * right[i]);
        }
        return result;
    }
};

