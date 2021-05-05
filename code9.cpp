/*
https://leetcode.com/problems/palindrome-number/
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.
*/

#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        int val = floor(log10(x));
        // cout << val << endl;
        int divisor = pow(10, val);
        // cout << divisor << endl;
        while (x > 9)
        {
            int left = x / divisor;
            int right = x % 10;
            // cout << left << " " << right << endl;
            if (left != right)
                return false;
            x = x % divisor;
            x = x / 10;
            // cout << x << endl;
            divisor = divisor / 100;
            if(x==0) return true;
        }
        // cout<<divisor<<endl;
        return divisor==1;
    }
};

int main()
{
    int number;
    cin >> number;
    Solution s;
    bool res = s.isPalindrome(number);
    cout << res << endl;
}