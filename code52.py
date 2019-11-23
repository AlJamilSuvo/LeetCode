'''

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

'''

class Solution(object):
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        self.res=0
        brd=[[0 for _ in range(n)] for _ in range(n)]
        self.solveNQueensBackTrack(brd,n,0)
        return self.res

    def solveNQueensBackTrack(self,brd,n,cur):
        if cur==n:
            self.res+=1
            return True
        for i in range(n):
            if self.isSafe(brd,cur,i,n):
                brd[cur][i]=1
                self.solveNQueensBackTrack(brd,n,cur+1)
            brd[cur][i]=0
            
    def isSafe(self,brd,x,y,n):
        for i in range(n):
            if brd[x][i]==1:
                return False
            if brd[i][y]==1:
                return False
        for i in range(n):
            if x-i>=0 and y-i>=0:
                if  brd[x-i][y-i]==1:
                    return False
            else:
                break
        for i in range(n):
            if x-i>=0 and y+i<n:
                if  brd[x-i][y+i]==1:
                    return False
            else:
                break
        for i in range(n):
            if x+i<0 and y-i>=0:
                if  brd[x+i][y-i]==1:
                    return False
            else:
                break

        for i in range(n):
            if x+i<n and y+i<n:
                if  brd[x+i][y+i]==1:
                    return False
            else:
                break
        return True

def print_brd(brd):
    for brd_ in brd:
        print(brd_)
    print()
        
        

s=Solution()
print(s.totalNQueens(4))