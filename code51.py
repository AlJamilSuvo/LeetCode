'''

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.


'''

import copy

class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        self.res=[]
        brd=[['.' for _ in range(n)] for _ in range(n)]
        self.solveNQueensBackTrack(brd,n,0)
        return self.res

    def solveNQueensBackTrack(self,brd,n,cur):
        if cur==n:
            ans=[]
            for single_brd in brd:
                ans_str=''
                for val in single_brd:
                    ans_str+=val
                ans.append(ans_str)
            self.res.append(ans)
            return True
        for i in range(n):
            if self.isSafe(brd,cur,i,n):
                brd[cur][i]='Q'
                self.solveNQueensBackTrack(brd,n,cur+1)
            brd[cur][i]='.'
            
    def isSafe(self,brd,x,y,n):
        for i in range(n):
            if brd[x][i]=='Q':
                return False
            if brd[i][y]=='Q':
                return False
        for i in range(n):
            if x-i>=0 and y-i>=0:
                if  brd[x-i][y-i]=='Q':
                    return False
            else:
                break
        for i in range(n):
            if x-i>=0 and y+i<n:
                if  brd[x-i][y+i]=='Q':
                    return False
            else:
                break
        for i in range(n):
            if x+i<0 and y-i>=0:
                if  brd[x+i][y-i]=='Q':
                    return False
            else:
                break

        for i in range(n):
            if x+i<n and y+i<n:
                if  brd[x+i][y+i]=='Q':
                    return False
            else:
                break
        return True

def print_brd(brd):
    for brd_ in brd:
        print(brd_)
    print()
        
        

s=Solution()
print(s.solveNQueens(4))

