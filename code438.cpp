#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        map<char, int> originalCount;
        map<char, int> foundCount;
        for (int i = 0; i < p.size(); i++)
        {
            originalCount[p[i]] += 1;
        }
        int totalExpectedCount = p.size();
        int currentFoundCount = 0;
        int lastResetIndex = -1;
        vector<int> res;
        int left = 0;
        int right = 0;
        for (int right = 0; right < s.size(); right++)
        {
            // cout << left << " " << s[left] << " " << right << " " << s[right] << endl;
            foundCount[s[right]] += 1;
            // cout << foundCount[s[right]] << " " << originalCount[right] << endl;
            if (foundCount[s[right]] > originalCount[s[right]])
            {
                while (s[left] != s[right])
                {
                    foundCount[s[left]] -= 1;
                    left++;
                }
                left += 1;
                foundCount[s[right]] -= 1;
            }
            else
            {
                if (right - left + 1 == p.size())
                {
                    // cout << "res = " << left << endl;
                    res.push_back(left);
                    foundCount[s[left]] -= 1;
                    left++;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    s.findAnagrams("cbaebabacd", "abc");
}