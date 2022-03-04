#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    stack<int> normalStack;
    stack<int> minStack;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        normalStack.push(val);
        if (minStack.empty())
        {
            minStack.push(val);
        }
        else if (val <= minStack.top())
            minStack.push(val);
    }

    void pop()
    {
        int val = normalStack.top();
        normalStack.pop();
        if (val == minStack.top())
            minStack.pop();
    }

    int top()
    {
        return normalStack.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */