#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        for (int i = 0; i < 9; i++)
        {
            unordered_map<char, bool> seen1;
            unordered_map<char, bool> seen2;
            for (int j = 0; j < 9; j++)
            {
                char c1 = board[i][j];

                char c2 = board[j][i];
                if (seen1[c1] && c1 != '.')
                    return false;
                if (seen2[c2] && c2 != '.')
                    return false;
                seen1[c1] = true;
                seen2[c2] = true;
            }
        }

        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                unordered_map<char, bool> seen;

                for (int x = i; x < i + 3; x++)
                {
                    for (int y = j; y < j + 3; y++)
                    {
                        char c = board[x][y];
                        if (seen[c] && c != '.')
                            return false;
                        seen[c] = true;
                    }
                }
            }
        }
        return true;
    }
};