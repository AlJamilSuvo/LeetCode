#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.length() - 1;
        while (left < right)
        {
            bool lAn = isAlphaNumaric(s[left]);
            bool rAn = isAlphaNumaric(s[right]);

            if (lAn && rAn)
            {
                if (getProcessedChar(s[left]) != getProcessedChar(s[right]))
                    return false;
                left++;
                right--;
            }
            else if (!lAn && rAn)
                left++;
            else if (lAn && !rAn)
                right--;
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }

    bool isAlphaNumaric(char c)
    {
        bool l = c >= 'a' && c <= 'z';
        bool u = c >= 'A' && c <= 'Z';
        bool d = c >= '0' && c <= '9';
        return l || u || d;
    }

    char getProcessedChar(char c)
    {
        if (c >= 'A' && c <= 'Z')
            return c - 'A' + 'a';
        else
            return c;
    }
};