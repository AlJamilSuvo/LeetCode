'''

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


'''

class Solution(object):
    def climbStairs(self, n):
        dp=[-1 for _ in range(n+1)]
        return self.findClimbStairs(n,dp)

       
    def findClimbStairs(self,n,dp):
        if n==0:
            return 1
        if dp[n]!=-1:
            return dp[n]
        cnt=self.findClimbStairs(n-1,dp)
        if n>=2:
            cnt+=self.findClimbStairs(n-2,dp)
        dp[n]=cnt
        return cnt

s=Solution()
print(s.climbStairs(2))
print(s.climbStairs(3))