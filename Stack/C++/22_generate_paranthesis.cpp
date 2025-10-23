/*
* RUNTIME: 3 ms - Beats 71.59% of C++ submissions
* MEMORY - 11.03 MB - Beats 96.46% of submissions
*/

#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <unordered_map>
#include <functional>
using namespace std;

/* Thoughtprocess:
* 1. Define an empty stack to hold tuples of (current_string, opened_count, closed_count)
* 2. Define a result vector to store all valid parenthesis combinations
* 3. Loop while the stack is not empty
* 4. Pop the top element (the current state of our string and counts)
* 5. If both opened and closed counts equal n → add the string to result
* 6. If closed < opened → we can safely add a closing parenthesis “)”
* 7. If opened < n → we can add an opening parenthesis “(”
* 8. Continue until all valid combinations are generated
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        stack<tuple<string, int, int>> stk;  // (current_string, opened, closed)
        stk.push({"", 0, 0});

        while (!stk.empty()) {
            auto [s, opened, closed] = stk.top();
            stk.pop();

            if (opened == n && closed == n) {
                result.push_back(s);
                continue;
            }

            if (closed < opened) {
                stk.push({s + ")", opened, closed + 1});
            }

            if (opened < n) {
                stk.push({s + "(", opened + 1, closed});
            }
        }

        return result;
    }
};