/*
* RUNTIME: 0 ms - Beats 100.00% of submissions  - don´t know how 0 ms is even possible
* MEMORY - 17.37 MB - Beats 11.74% of submissions
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
* 1. Define a stack to store operands
* 2. Define operations - what happens when "+" is in the list, etc.
* 3. Check if the current token is in the operations map
* 4. If not, simply push the number onto the stack
* 5. Else, apply the predefined operation using the two most recent values
* 7. Return the remaining element on the stack
*
*/


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        unordered_map<string, function<int(int,int)>> ops = 
        {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}
        };
        
        for (string s : tokens)
        {
            if ( ops.find(s) == ops.end())
            {
                st.push(stoi(s));
            }
            else
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(ops.find(s)->second(left, right));
            }
        }
        return st.top();
    }
};