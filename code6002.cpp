#include <bits/stdc++.h>
using namespace std;

class Bitset
{
    vector<int> original;
    vector<int> flipped;
    string originalStr = "";
    string filppedStr = "";
    bool isFlipped;
    int size;
    int cnt;

public:
    Bitset(int size) : size(size), original(size), flipped(size)
    {
        for (int i = 0; i < size; i++)
        {
            original[i] = 0;
            flipped[i] = 1;
            originalStr += "0";
            filppedStr += "1";
        }
        isFlipped = false;
        cnt = 0;
    }

    void set(int idx)
    {
        if (original[idx] == 1)
            return;

        original[idx] = 1;
        flipped[idx] = 0;
        originalStr[idx] = '1';
        filppedStr[idx] = '0';
        cnt += 1;
    }

    void reset(int idx)
    {
        if (original[idx] == 0)
            return;

        original[idx] = 0;
        flipped[idx] = 1;
        originalStr[idx] = '0';
        filppedStr[idx] = '1';
        cnt -= 1;
    }

    void fix(int idx)
    {
        if (isFlipped)
        {
            reset(idx);
        }
        else
            set(idx);
    }

    void unfix(int idx)
    {
        if (isFlipped)
        {
            set(idx);
        }
        else
            reset(idx);
    }

    void flip()
    {
        isFlipped = !isFlipped;
    }

    bool all()
    {
        if (isFlipped)
            return cnt == 0;
        else
            return cnt == size;
    }

    bool one()
    {
        if (isFlipped)
            return cnt < size;
        else
            return cnt > 0;
    }

    int count()
    {
        if (isFlipped)
            return size - cnt;
        else
            return cnt;
    }

    string toString()
    {
        if (isFlipped)
            return filppedStr;
        else
            return originalStr;
    }
};
