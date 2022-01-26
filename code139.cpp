#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {

        unordered_map<int, bool> dp;

        for (int i = 0; i < s.length(); i++)
        {
            for (auto word : wordDict)
            {
                if (i + 1 >= word.length())
                {
                    if (s.substr(i + 1 - word.length(), word.length()) == word)
                    {
                        bool prev = true;
                        int prevIndex = i - word.size();
                        if (prevIndex >= 0)
                            prev = dp[prevIndex];
                        if (prev)
                        {
                            dp[i] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[s.length() - 1];
    }
};

int main()
{
    vector<string> words = {"leet", "code"};
    Solution s;
    cout << s.wordBreak("leetcode", words) << endl;
    ;
}