/*
* RUNTIME: 37 ms - Beats 79.99% of C++ submissions
* MEMORY - 100.68 MB - Beats 92.21% of submissions
*/

#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <unordered_map>
#include <functional>
using namespace std;


// My thought process:
//
// 1. create tuple pairing position and assigned speed
// 2. reverse sort the tuple to start a stack from the closest target position
// 3. create empty stack
// 4. iterate through the tuple
// 5. append stepcount needed to reach the target into the stack
// 6. if following position is faster than the last they will eventually meet. This results in a fleet
// 7. Therefore pop the last element and check the next
// 8. Otherwise this counts as "unique"-fleet.
// 9. The next position following a new fleet checks the top position of the fleet.
// 10. Return the length of the stack to get the amount of Fleets


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> linear_pair;
        linear_pair.reserve(position.size());
        for (int i = 0; i < position.size(); i++) {
            linear_pair.emplace_back(position[i], speed[i]); 
        }
        // sorting following array means O(log n)
        sort(linear_pair.begin(), linear_pair.end(),
             [](auto& a, auto& b) { return a.first > b.first; });

        vector<double> stack;
        for (auto& p : linear_pair) {  // iteration through n-entries results in O(n)
            int pos = p.first;
            int sp = p.second;

            double steps = (double)(target - pos) / sp; // less steps means faster car
            stack.push_back(steps);
            if (stack.size() >= 2) {
                if (stack.back() <= stack[stack.size() - 2]) {
                    stack.pop_back();
                }
            }
        }
        return stack.size(); // Answer should have time complexity O(n log n)
    }
};