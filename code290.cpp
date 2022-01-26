#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        int startIndex = 0;
        vector<string> words;
        int i = 0;
        for (i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                words.push_back(s.substr(startIndex, i - startIndex));
                startIndex = i + 1;
            }
        }
        words.push_back(s.substr(startIndex, i - startIndex));
        map<char, string> mp1;
        map<string, char> mp2;
        map<char, bool> seen1;
        map<string, bool> seen2;
        if (words.size() != pattern.length())
            return false;
        for (i = 0; i < pattern.length(); i++)
        {
            if (seen1[pattern[i]] || seen2[words[i]])
            {
                if (mp1[pattern[i]] != words[i] || mp2[words[i]] != pattern[i])
                    return false;
            }
            else
            {
                seen1[pattern[i]] = true;
                seen2[words[i]] = true;
                mp1[pattern[i]] = words[i];
                mp2[words[i]] = pattern[i];
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.wordPattern("abba", "dog cat cat dog") << endl;
    ;
}