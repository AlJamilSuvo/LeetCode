#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumRemoval(vector<int> &beans)
    {
        sort(beans.begin(), beans.end());
        long long leftSum = 0;
        long long rightSum = 0;
        int posStart = 0;
        int posEnd = 0;
        for (int i = 0; i < beans.size(); i++)
        {
            if (beans[i] == beans[0])
                posEnd = i;
            if (beans[i] != beans[0])
                rightSum += beans[i];
        }
        int nextPos = posEnd + 1;
        long long result = leftSum + rightSum;
        leftSum = (posEnd - posStart + 1) * beans[posStart];
        cout << result << endl;
        while (nextPos < beans.size())
        {
            posStart = nextPos;
            for (int i = posStart; i < beans.size(); i++)
            {
                if (beans[i] == beans[posStart])
                    posEnd = i;
                else
                    break;
            }

            rightSum = rightSum - (beans.size() - 1 - posEnd) * (beans[posStart] - beans[posStart - 1]);
            rightSum -= (posEnd - posStart + 1) * beans[posStart-1];
            cout << beans[posStart] << " " << leftSum << " " << rightSum << endl;
            if (leftSum + rightSum < result)
                result = leftSum + rightSum;
            nextPos = posEnd + 1;
            leftSum += (posEnd - posStart + 1) * beans[posStart];
        }
        return result;
    }
};

int main()
{
    vector<int> res = {4, 1, 6, 5};
    Solution s;
    cout << s.minimumRemoval(res) << endl;
}