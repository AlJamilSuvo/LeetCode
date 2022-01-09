#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int beamCount = 0;
        int prevRowDeviceCount = 0;
        for (int i = 0; i < bank.size(); i++)
        {
            int currentRowDeviceCount = std::count_if(bank[i].begin(), bank[i].end(), [](char c)
                                                      { return c == '1'; });
            beamCount += prevRowDeviceCount * currentRowDeviceCount;
            if (currentRowDeviceCount != 0)
                prevRowDeviceCount = currentRowDeviceCount;
        }
        return beamCount;
    }
};

int main()
{
    Solution s;
    vector<string> i1 = {"011001", "000000", "010100", "001000"};
    vector<string> i2 = {"000", "111", "000"};
    cout << s.numberOfBeams(i1) << endl;
    cout << s.numberOfBeams(i2) << endl;
}