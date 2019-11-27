'''

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?



An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

'''

class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        

        m=len(obstacleGrid)
        n=len(obstacleGrid[0])
        dp=[[-1 for _ in range(n)] for _ in range(m)]
        return self.findUniquePaths(0,0,m,n,obstacleGrid,dp)

    def findUniquePaths(self,x,y,m,n,obstacleGrid,dp):
        if x==m-1 and y==n-1:
            return 1-obstacleGrid[x][y]
        if dp[x][y]!=-1:
            return dp[x][y]
        if obstacleGrid[x][y]==1:
            return 0
        down_path=0
        right_path=0
        if x<m-1:
            down_path=self.findUniquePaths(x+1,y,m,n,obstacleGrid,dp)
        if y<n-1:
            right_path=self.findUniquePaths(x,y+1,m,n,obstacleGrid,dp)
        dp[x][y]=down_path+right_path
        return dp[x][y]
s=Solution()
print(s.uniquePathsWithObstacles([[0,1]]))