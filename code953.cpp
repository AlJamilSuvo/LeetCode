#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        map<char, int> order_map;
        for (int i = 0; i < order.size(); i++)
        {
            order_map[order[i]] = i;
        }
        for (int i = 1; i < words.size(); i++)
        {
            if (!compareWord(words[i - 1], words[i], order_map))
                return false;
        }
        return true;
    }

    bool compareWord(string &word1, string &word2, map<char, int> order_map)
    {
        int len = min(word1.length(), word2.length());
        for (int i = 0; i < len; i++)
        {

            int i1 = order_map[word1[i]];
            int i2 = order_map[word2[i]];
            if (i1 < i2)
                return true;
            if (i1 > i2)
                return false;
        }
        return word1.length() <= word2.length();
    }
};

int main()
{

    vector<string> input1 = {"hello", "leetcode"};
    Solution s;
    cout << s.isAlienSorted(input1, "hlabcdefgijkmnopqrstuvwxyz") << endl;
}