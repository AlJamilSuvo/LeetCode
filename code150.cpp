#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++)
        {
            int a, b;
            if (tokens[i] == "+")
            {
                getValues(stk, a, b);
                stk.push(a + b);
            }
            else if (tokens[i] == "-")
            {
                getValues(stk, a, b);
                stk.push(a - b);
            }
            else if (tokens[i] == "*")
            {
                getValues(stk, a, b);
                stk.push(a * b);
            }
            else if (tokens[i] == "/")
            {
                getValues(stk, a, b);
                stk.push(a / b);
            }
            else
            {
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
    void getValues(stack<int> &stk, int &a, int &b)
    {
        b = stk.top();
        stk.pop();
        a = stk.top();
        stk.pop();
    }
};