#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {

        unordered_map<string, int> wordFreq;
        int totalLen = 0;
        int singleWordLen = wor;
        for (int i = 0; i < words.size(); i++)
        {
            totalLen += words[i].length();
            for (int j = 0; j < words[i].length(); j++)
            {
                freq[words[i][j]]++;
            }
        }
        vector<int> res;
        unordered_map<char, int> sFreq;
        int left = 0;
        int right = 0;
        while (right < s.length())
        {
            sFreq[s[right]]++;
            while (sFreq[s[right]] > freq[s[right]])
            {
                sFreq[s[left]]--;
                left++;
            }
            if (right - left + 1 == totalLen)
            {
                res.push_back(left);
                sFreq[s[left]]--;
                left++;
            }
            right++;
        }
        return res;
    }
};