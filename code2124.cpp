#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkString(string s)
    {
        bool isBFound = false;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]=='b') {
                isBFound = true;
            }
            if(s[i]=='a' && isBFound) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.checkString("aaabbb") << endl;
    cout << s.checkString("abab") << endl;
    cout << s.checkString("bbb") << endl;
    cout << s.checkString("aaa") << endl;
}