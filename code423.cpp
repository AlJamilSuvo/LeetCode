#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string originalDigits(string s)
    {
        vector<char> specialChar = {'g', 'u', 'w', 'x', 'z', 'f', 'h', 'v', 'o', 'i'};
        vector<int> specialChatDigit = {8, 4, 2, 6, 0, 5, 3, 7, 1, 9};
        vector<string> digitStr = {"eight", "four", "two", "six", "zero", "five", "three", "seven", "one", "nine"};

        map<char, int> cntMap;
        for (int i = 0; i < s.length(); i++)
        {
            cntMap[s[i]] += 1;
        }

        int totalFound = 0;
        vector<int> res;
        while (totalFound < s.length())
        {
            for (int i = 0; i < specialChar.size(); i++)
            {
                // cout << specialChar[i] << endl;
                if (cntMap[specialChar[i]] > 0)
                {
                    res.push_back(specialChatDigit[i]);
                    // cout << specialChatDigit[i] << endl;
                    for (int j = 0; j < digitStr[i].size(); j++)
                    {
                        cntMap[digitStr[i][j]] -= 1;
                    }
                    totalFound += digitStr[i].length();
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        string result = "";
        for (int i = 0; i < res.size(); i++)
            result += (char)('0' + res[i]);
        return result;
    }
};

class Solution
{
public:
    string originalDigits(string s)
    {
        map<char, int> cntMap;
        for (int i = 0; i < s.length(); i++)
        {
            cntMap[s[i]] += 1;
        }
        vector<int> digitCnt(10, 0);
        digitCnt[8] = cntMap['g'];
        digitCnt[4] = cntMap['u'];
        digitCnt[2] = cntMap['w'];
        digitCnt[6] = cntMap['x'];
        digitCnt[0] = cntMap['z'];
        digitCnt[5] = cntMap['f'] - digitCnt[4];
        digitCnt[3] = cntMap['h'] - digitCnt[8];
        digitCnt[7] = cntMap['v'] - digitCnt[5];
        digitCnt[1] = cntMap['o'] - digitCnt[2] - digitCnt[4] - digitCnt[0];
        digitCnt[9] = cntMap['i'] - digitCnt[5] - digitCnt[6] - digitCnt[8];

        string result = "";
        for (int i = 0; i <= 9; i++)
        {
            for (int j = 0; j < digitCnt[i]; j++)
            {
                result += (char)('0' + i);
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.originalDigits("owoztneoer") << endl;
}