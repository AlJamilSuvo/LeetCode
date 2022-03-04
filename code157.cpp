#include <bits/stdc++.h>
using namespace std;

/**
 * The read4 API is defined in the parent class Reader4.
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
    int read(char *buf, int n)
    {
        char buf4[4];
        int pt = 0;
        while (true)
        {
            int read = read4(buf4);
            if (read == 0)
                return pt;
            if (read + pt > n)
            {
                read = n - pt;
            }
            for (int i = 0; i < read; i++)
            {
                buf[pt] = buf4[i];
                pt++;
            }
            if(pt==n) return pt;
        }
        return 0;
    }
};