#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> heap;
        int sum = 0;
        for (auto pile : piles)
        {
            heap.push(pile);
            sum += pile;
        }
        for (int i = 0; i < k; i++)
        {
            int top = heap.top();
            heap.pop();
            int changed = top - floor(top / 2);
            sum -= floor(top / 2);
            heap.push(changed);
        }
        return sum;
    }
};