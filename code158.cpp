#include <bits/stdc++.h>
using namespace std;

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

int read4(char *buf4);

class Solution
{
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */

    vector<char> fileContents;
    bool isAlreadyRead = false;
    int currentPnt = 0;

    int read(char *buf, int n)
    {
        if (!isAlreadyRead)
            readFullFile();
        int len = min((int64_t)n, (int64_t)fileContents.size() - currentPnt);
        for (int i = 0; i < len; i++)
        {
            buf[i] = fileContents[i + currentPnt];
        }
        currentPnt += len;
        return len;
    }

    void readFullFile()
    {
        char buf4[4];
        while (true)
        {
            int read = read4(buf4);
            if (read == 0)
                break;
            for (int i = 0; i < read; i++)
            {
                fileContents.push_back(buf4[i]);
            }
        }
        isAlreadyRead = true;
    }
};