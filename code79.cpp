#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {

        vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));

        vector<vector<vector<bool>>> isAlreadyChecked(board.size(), vector(board[0].size(), vector(word.length(), false)));

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (check(board, word, i, j, 0, isVisited, isAlreadyChecked))
                    return true;
            }
        }
        return false;
    }

    bool check(vector<vector<char>> &board, string word, int x, int y, int wordIndex, vector<vector<bool>> isVisited, vector<vector<vector<bool>>> &isAlreadyChecked)
    {

        if (isAlreadyChecked[x][y][wordIndex])
            return false;

        if (board[x][y] != word[wordIndex])
        {
            return false;
        }

        if (wordIndex == word.length() - 1)
            return true;

        isVisited[x][y] = true;

        if (x > 0 && !isVisited[x - 1][y])
        {
            if (check(board, word, x - 1, y, wordIndex + 1, isVisited, isAlreadyChecked))
                return true;
        }

        if (y > 0 && !isVisited[x][y - 1])
        {
            if (check(board, word, x, y - 1, wordIndex + 1, isVisited, isAlreadyChecked))
                return true;
        }

        if (x < board.size() - 1 && !isVisited[x + 1][y])
        {
            if (check(board, word, x + 1, y, wordIndex + 1, isVisited, isAlreadyChecked))
                return true;
        }

        if (y < board[0].size() - 1 && !isVisited[x][y + 1])
        {
            if (check(board, word, x, y + 1, wordIndex + 1, isVisited, isAlreadyChecked))
                return true;
        }

        isAlreadyChecked[x][y][wordIndex] = true;

        return false;
    }
};