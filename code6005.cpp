#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        map<int, int> oddPosCnt;
        map<int, int> eventPosCnt;

        int me1 = -1;
        int me2 = -1;
        int mo1 = -1;
        int mo2 = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            int n = nums[i];
            if (i % 2 == 0)
            {
                eventPosCnt[n]++;
                if (n == me1)
                    continue;
                if (eventPosCnt[n] > eventPosCnt[me1])
                {
                    me2 = me1;
                    me1 = n;
                    continue;
                }

                if (eventPosCnt[n] > eventPosCnt[me2])
                {
                    me2 = n;
                }

        
            }
            else
            {
                oddPosCnt[n]++;
                if (n == mo1)
                    continue;
                if (oddPosCnt[n] > oddPosCnt[mo1])
                {
                    mo2 = mo1;
                    mo1 = n;
                    continue;
                }

                if (oddPosCnt[n] > oddPosCnt[mo2])
                {
                    mo2 = n;
                }
            }
        }

        cout << me1 << " " << me2 << " " << mo1 << " " << mo2 << endl;

        int ce1 = nums.size() / 2 + (nums.size() % 2) - eventPosCnt[me1];
        int ce2 = nums.size() / 2 + (nums.size() % 2) - eventPosCnt[me2];

        int co1 = nums.size() / 2 + -oddPosCnt[mo1];
        int co2 = nums.size() / 2 + -oddPosCnt[mo2];

        cout << ce1 << " " << ce2 << " " << co1 << " " << co2 << endl;

        if (me1 != mo1)
        {
            return ce1 + co1;
        }
        else
            return min(ce1 + co2, ce2 + co1);
    }
};

int main()
{
    Solution s;
    vector<int> in = {1, 2, 2, 2, 2};
    cout<<s.minimumOperations(in)<<endl;
}