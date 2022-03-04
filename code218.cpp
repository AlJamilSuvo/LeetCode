#include <bits/stdc++.h>
using namespace std;

template <typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>>
{
public:
    bool remove(const T &value)
    {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end())
        {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }
        else
        {
            return false;
        }
    }
};
class Point
{
public:
    int pos;
    int height;
    bool isStart;

    void print()
    {
        cout << pos << "," << height << "," << isStart << endl;
    }
};

class PointCompare
{
public:
    bool operator()(const Point &p1, const Point &p2)
    {
        if (p1.pos == p2.pos)
        {
            if (p1.isStart == p2.isStart)
            {
                if (p1.isStart == true)
                {
                    return p1.height >= p2.height;
                }
                else
                    return p1.height <= p2.height;
            }
            else
            {
                return p1.isStart;
            }
        }
        else
            return p1.pos < p2.pos;
    }
};

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<Point> points;
        for (int i = 0; i < buildings.size(); i++)
        {
            Point p1;
            Point p2;
            p1.pos = buildings[i][0];
            p1.height = buildings[i][2];
            p1.isStart = true;

            p2.pos = buildings[i][1];
            p2.height = buildings[i][2];
            p2.isStart = false;

            points.push_back(p1);
            points.push_back(p2);
        }
        sort(points.begin(), points.end(), PointCompare());

        for (int i = 0; i < points.size(); i++)
        {
            points[i].print();
        }

        return {{}};
    }
};

int main()
{
    vector<vector<int>> bui = {{2, 9, 10}, {2, 9, 5}, {9, 10, 12}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    Solution s;
    s.getSkyline(bui);
}