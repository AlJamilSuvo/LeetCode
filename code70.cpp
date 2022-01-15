class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int result = 0;
        int prev_1 = 2;
        int prev_2 = 1;
        for (int i = 3; i <= n; i++)
        {
            result = prev_1 + prev_2;
            prev_2 = prev_1;
            prev_1 = result;
        }
        return result;
    }
};