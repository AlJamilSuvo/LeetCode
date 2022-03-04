#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue)
    {

        if (k == s.length())
            return s;

        int64_t last = 0;
        int64_t mul = 1;
        for (int i = 0; i < k; i++)
        {
            int v = s[i] - 'a' + 1;
            int64_t cur = (v * mul) % modulo;
            mul = (mul * power) % modulo;
            last = cur + last;
        }
        int j = 0;
        while (true)
        {
            if (last % modulo == hashValue)
                return s.substr(j, k);

            last = (last % modulo) / (power % modulo);
            if (j + k >= s.length())
                break;
            int v = s[j + k] - 'a' + 1;
            int64_t cur = (v * mul) % modulo;
            last = last + cur;
        }

        return "";
    }
};

int main()
{
    Solution s;
    cout << s.subStrHash("xqgfatvtlwnnkxipmipcpqwbxihxblaplpfckvxtihonijhtezdnkjmmk", 22, 51, 41, 9) << endl;

    // cout << (242 % 24) << endl;
    // cout << (392 % 24) << endl;
    // cout << ((242 * 392) % 24) << endl;
}

/*

"xqgfatvtlwnnkxipmipcpqwbxihxblaplpfckvxtihonijhtezdnkjmmk"
22
51
41
9

*/