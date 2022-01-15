#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct sort_people
    {
        inline bool operator()(const vector<int> &v1, const vector<int> &v2)
        {
            if (v1[0] == v2[0])
            {
                return v1[1] < v2[1];
            }
            return v1[0] > v2[0];
        };
    };
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {

        sort(people.begin(), people.end(), sort_people());

        map<int, vector<int>> arr;
        for (int i = 0; i < people.size(); i++)
        {
            arr[i] = people[i];
            cout << arr[i][0] << " " << arr[i][1] << endl;
        }
        for (int i = 0; i < people.size(); i++)
        {
            vector<int> curr = arr[i];
            int height = arr[i][0];
            int count = arr[i][1];
            int found = 0;
            int possible_position = 0;

            for (int j = 0; j < i; j++)
            {
                if (arr[j][0] >= height)
                {
                    found += 1;
                    if (found == count)
                        possible_position = j + 1;
                }
            }

            if (found > count)
            {
                for (int j = i; j > possible_position; j--)
                {
                    arr[j] = arr[j - 1];
                }
                arr[possible_position] = curr;
            }
        }

        cout << "after " << endl;

        for (int i = 0; i < people.size(); i++)
        {
            people[i] = arr[i];
            cout << arr[i][0] << " " << arr[i][1] << endl;
        }

        return people;
    }
};

int main()
{
    vector<vector<int>> test = {{6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4}};
    Solution s;
    s.reconstructQueue(test);
}