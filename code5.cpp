/*
Given a string s, return the longest palindromic substring in s.
https://leetcode.com/problems/longest-palindromic-substring/
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {

        map<pair<int, int>, bool> mp;
        int currentIndex = 0;
        int frontIndex = 0;
        int backIndex = 0;
        int maxLength = -1;
        bool hasEvenLength = false;
        hasEvenLength = true;
        string a;
        for (int i = 0; i < s.length(); i++)
        {
            a = a + s[i] + '_';
        }
        // a = a + s[s.length() - 1];
        s = a;
        // cout<<s<<endl;

        string res;
        for (currentIndex = 0; currentIndex < s.length(); currentIndex++)
        {
            frontIndex = currentIndex;
            backIndex = currentIndex;
            while (frontIndex < s.length() && backIndex >= 0 && s[frontIndex] == s[backIndex])
            {
                int length = frontIndex - backIndex;
                if (length > maxLength)
                {
                    res = s.substr(backIndex, frontIndex - backIndex + 1);
                    maxLength = frontIndex - backIndex;
                }
                frontIndex++;
                backIndex--;
            }
        }
        // cout<<res<<endl;
        a="";
        for (int i = 0; i < res.length(); i++)
        {
            if (res[i] != '_')
                a = a + res[i];
        }
        res = a;
        return res;
    }
};

int main()
{
    Solution s;
    string input;
    cin >> input;
    string result = s.longestPalindrome(input);
    cout << result << endl;
    return main();
}