#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
    {
        unordered_map<int, int> wBitcnt;

        for (int i = 0; i < words.size(); i++)
        {
            int wBit = stringToBit(words[i]);
            wBitcnt[wBit]++;
        }
        vector<int> res(puzzles.size(), 0);
        for (int i = 0; i < puzzles.size(); i++)
        {
            int cnt = 0;
            int first = 1 << (puzzles[i][0] - 'a');

            int pBit = stringToBit(puzzles[i], 1);

            for (int subPBit = pBit; subPBit; subPBit = (subPBit - 1) & pBit)
            {
                cnt += wBitcnt[subPBit | first];
            }

            res[i] = cnt;
        }
        return res;
    }

    int stringToBit(const string &s, int startIndex = 0)
    {
        int bit = 0;
        for (int i = startIndex; i < s.length(); i++)
        {
            bit = bit | (1 << (s[i] - 'a'));
        }
        return bit;
    }
};

int strToBit(const string &s, int startIndex = 0)
{
    int bit = 0;
    for (int i = startIndex; i < s.length(); i++)
    {
        bit = bit | (1 << (s[i] - 'a'));
    }
    return bit;
}

string bitToStr(int bit)
{
    string s;
    for (int i = 0; i < 26; i++)
    {
        if (bit & 1)
            s += (char)('a' + i);
        bit = bit >> 1;
    }
    return s;
}

int main()
{
    // vector<string> words = {"aaaa", "asas", "able", "ability", "actt", "actor", "access"};
    // vector<string> puzzles = {"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"};
    // Solution s;
    // s.findNumOfValidWords(words, puzzles);

    string s = "aboveyz";
    int bit = strToBit(s);
    bitset<32> bs(bit);
    cout << bs << endl;

    cout << bitToStr(bit) << endl;

    for (int sub = bit; sub; sub = (sub - 1) & bit)
    {
        bitset<32> bsub(sub);
        cout << bsub << " "<<bitToStr(sub)<<endl;
    }
}