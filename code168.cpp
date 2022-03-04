#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string result = "";
        while (columnNumber > 0)
        {
            int mod = columnNumber % 26;
            if (mod == 0)
            {
                result = "Z" + result;
                columnNumber = (columnNumber / 26) - 1;
            }
            else
            {
                result = ((char)('A' + mod - 1)) + result;
                columnNumber = columnNumber / 26;
            }
        }
        return result;
    }
};