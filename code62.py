'''
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

'''


class Solution(object):
    def uniquePaths(self, m, n):
        self.dp=[[-1 for _ in range(n)] for _ in range(m)]
        return self.findUniquePaths(0,0,m,n)


    def findUniquePaths(self,x,y,m,n):
        if x==m-1 and y==n-1:
            return 1
        if self.dp[x][y]!=-1:
            return self.dp[x][y]
        down_path=0
        right_path=0
        if x<m-1:
            down_path=self.findUniquePaths(x+1,y,m,n)
        if y<n-1:
            right_path=self.findUniquePaths(x,y+1,m,n)
        self.dp[x][y]=down_path+right_path
        return self.dp[x][y]
        
        
s=Solution()
print(s.uniquePaths(7,3))