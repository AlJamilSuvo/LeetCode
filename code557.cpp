#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int start = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                reverseString(s, start, i - 1);
                start = i + 1;
            }
        }
        reverseString(s, start, s.length() - 1);
        return s;
    }

    void reverseString(string &s, int left, int right)
    {
        if (s.length() <= left)
            return;
        while (left < right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};