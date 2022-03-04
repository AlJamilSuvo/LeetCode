#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<int> stk;
        int index = 0;
        for (index = 0; index < num.length(); index++)
        {
            int d = num[index] - '0';
            while (!stk.empty() && stk.top() > d && k > 0)
            {
                stk.pop();
                k--;
            }
            stk.push(d);
            if (k == 0)
                break;
        }
        index++;
        for (int i = 0; i < k; i++)
        {
            stk.pop();
        }
        string temp = "";
        while (!stk.empty())
        {
            temp = (char)(stk.top() + '0') + temp;
            stk.pop();
        }

        string answer = "";
        for (int i = 0; i < temp.size(); i++)
        {
            if (answer == "" && temp[i] == '0')
                continue;
            answer+=temp[i];
        }

        for (; index < num.length(); index++)
        {
            if (answer == "" && num[index] == '0')
                continue;
            answer += num[index];
        }

        if (answer == "")
            answer = "0";
        return answer;
    }
};