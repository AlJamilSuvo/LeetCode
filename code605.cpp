#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int maxNewPlantCount = 0;
        bool isPrevPlant = false;
        for (int i = 0; i < flowerbed.size(); i++)
        {
            bool isNextPlant = false;
            if (i != flowerbed.size() - 1)
                isNextPlant = flowerbed[i + 1] == 1;
            if (flowerbed[i] == 1)
            {
                isPrevPlant = true;
            }
            else
            {
                if (!isPrevPlant && !isNextPlant)
                {
                    maxNewPlantCount++;
                    isPrevPlant = true;
                }
                else
                    isPrevPlant = false;
            }
        }
        return n <= maxNewPlantCount;
    }
};