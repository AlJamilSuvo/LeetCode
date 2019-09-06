class Solution(object):
    def solveSudoku(self, board):
        self.row=[]
        self.col=[]
        self.box=dict()
        self.outcomes=[str(i) for i in range(1,10)]
        for _ in range(0,9):
            self.row.append(set())
            self.col.append(set())
        for i in range(0,3):
            for j in range(0,3):
                self.box[(i,j)]=set()
        for i in range(0,9):
            for j in range(0,9):
                self.addToSet(board,i,j)
                
        self.solveByBackTrack(board)

    def solveByBackTrack(self,board):
        for r in range(0,9):
            for c in range(0,9):
                if board[r][c]=='.':           
                    for out in self.outcomes:
                        if self.isSafe(r,c,out):
                            board[r][c]=out
                            self.addToSet(board,r,c)
                            res=self.solveByBackTrack(board)
                            if res:
                                return True
                            else:
                                self.removeFromSet(board,r,c)
                                board[r][c]='.'
                    board[r][c]='.'
                    return False
        return True


    def isSafe(self,r,c,target):
        return target not in self.row[r] and target not in self.col[c] and target not in self.box[(r//3,c//3)]


    def addToSet(self,board,i,j):
        if board[i][j]!='.':
            self.row[i].add(board[i][j])
            self.col[j].add(board[i][j])
            self.box[(i//3,j//3)].add(board[i][j])
    def removeFromSet(self,board,i,j):
        if board[i][j]!='.':
            self.row[i].remove(board[i][j])
            self.col[j].remove(board[i][j])
            self.box[(i//3,j//3)].remove(board[i][j])

s=Solution()
brd=[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
s.solveSudoku(brd)
print(brd)
