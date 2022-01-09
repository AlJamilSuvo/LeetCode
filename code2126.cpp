#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {

        int64_t m = mass;
        sort(asteroids.begin(), asteroids.end());
        for (auto a : asteroids)
        {
            if (m >= a)
                m += a;
            else
                return false;
        }
        return true;
    }
};

int main()
{
    vector<int> i1 = {3, 9, 19, 5, 21};
    vector<int> i2 = {4, 9, 23, 4};
    Solution s;
    cout << s.asteroidsDestroyed(10, i1) << endl;
    cout << s.asteroidsDestroyed(5, i2) << endl;
}