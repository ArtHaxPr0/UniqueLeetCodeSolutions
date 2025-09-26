/*
* RUNTIME: 0 ms - Beats 100.00% of submissions  - don´t know how 0 ms is even possible
* MEMORY - 23.54 MB - Beats 32.74% of submissions
*/

#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

/* Thoughtprocess:
* 1. initailize stack for input value and min value
* 2. if min-stack is empty first input is registered
* 3. push back min value and input value
* 
*/




class MinStack {
public:
    stack<int> inputStack;
    stack<int> minValStack;

    MinStack() {

    }
    
    void push(int val) {
        this->inputStack.push(val);
        if (this->minValStack.empty())
            this->minValStack.push(val);
        else if (val <= this->minValStack.top())
            this->minValStack.push(val);
    }
    
    void pop() {
        if (this->inputStack.top() == this->minValStack.top())
            this->minValStack.pop();
        this->inputStack.pop();
    }
    
    int top() {
        return this->inputStack.top();
    }
    
    int getMin() {
        return this->minValStack.top();
    }
};