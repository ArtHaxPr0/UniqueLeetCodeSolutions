/*
* RUNTIME: 0 ms - Beats 100.00% of submissions  - don´t know how 0 ms is even possible
* MEMORY - 7.63 MB - Beats 5.09% of submissions
*/

#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;


/* Thoughtprocess:
* 1. initailize stack
* 2. push opening brackets to stack
* 3. if closing bracket is found, check if the top of the stack is the corresponding opening bracket
* 4. if not, return false
* 5. if yes, pop the top of the stack
* 6. Repeat untill no possibilities are left
* 7. Return true if stack is empty
* 
*/


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s)
        {
            if ( c == '(' || c == '{' || c == '[')
                st.push(c);
            else if (st.empty())
                return false;
            else if (c == ')' and st.top() == '(')
                st.pop();
            else if (c == '}' and st.top() == '{')
                st.pop();
            else if (c == ']' and st.top() == '[')
                st.pop();
            else
                return false;
        }
        return st.empty();
    }
};