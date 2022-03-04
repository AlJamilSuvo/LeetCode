#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long smallestNumber(long long num)
    {

        if (num == 0)
            return 0;

        bool isNegative = false;

        if (num < 0)
            isNegative = true;

        if (isNegative)
            num = num * -1;

        int zeroCnt = 0;

        vector<int> digits;

        while (num > 0)
        {
            if (num % 10 == 0)
                zeroCnt++;
            else
                digits.push_back(num % 10);
            num = num / 10;
        }

        if (isNegative)
            sort(digits.begin(), digits.end(), greater<int>());
        else
            sort(digits.begin(), digits.end());

        long long res = 0;

        int i = 0;

        for (i = 0; i < digits.size(); i++)
        {
            if (i == 1 && !isNegative)
            {
                for (int j = 0; j < zeroCnt; j++)
                    res = res * 10;
            }
            res = res * 10;
            res = res + digits[i];
        }

        if (isNegative || i == 1)
        {
            for (int j = 0; j < zeroCnt; j++)
                res = res * 10;
        }

        if (isNegative)
            res = res * -1;
        return res;
    }
};