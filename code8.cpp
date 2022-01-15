#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int16_t value = 0;
        int sign = 1;
        bool isDigitStarted = false;
        for (auto ch : s)
        {
            if (ch == ' ' && !isDigitStarted)
                continue;
            else if (ch == '+' && !isDigitStarted)
            {
                sign = 1;
                isDigitStarted = true;
            }
            else if (ch == '-' && !isDigitStarted)
            {
                sign = -1;
                isDigitStarted = true;
            }
            else if (ch >= '0' && ch <= '9')
            {
                if (value > INT_MAX)
                    break;
                value = value * 10 + (ch - '0');
                isDigitStarted = true;
                if (value > INT_MAX)
                    break;
            }
            else
                break;
        }
        value = value * sign;
        if (value > INT_MAX)
            value = INT_MAX;
        if (value < INT_MIN)
            value = INT_MIN;
        return value;
    }
};