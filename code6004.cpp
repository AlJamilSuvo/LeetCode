#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countOperations(int num1, int num2)
    {
        int cnt = 0;
        while (num1 != 0 && num2 != 0)
        {
            cnt++;
            if (num1 == num2)
            {
                return cnt;
            }
            else
            {
                if (num1 > num2)
                {
                    num1 = num1 - num2;
                }
                else
                    num2 = num2 - num1;
            }
        }
        return cnt;
    }
};