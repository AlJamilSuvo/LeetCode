class Solution(object):
    def isValidSudoku(self, board):
        check=set()
        print(board[3])
        print(board[:,4])
        print(board[3:7,3:7])
        for r in range(0,len(board)):
            for c in range(0,len(board[r])):
                v=board[r][c]
                if v=='.':
                    continue
                key_row='r'+str(r)+'v:'+v
                key_col='c'+str(r)+'v:'+v
                key_box='b'+str(r//3)+str(c//3)+'v:'+v
                print(key_row,key_col,key_box)
                if key_row in check or key_col in check or key_box in check:
                    return False
                check.add(key_box)
                check.add(key_row)
                check.add(key_col)
        return True
s=Solution()
brd=[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
brd2=[["8","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
brd3=[[".",".","4",".",".",".","6","3","."],[".",".",".",".",".",".",".",".","."],["5",".",".",".",".",".",".","9","."],[".",".",".","5","6",".",".",".","."],["4",".","3",".",".",".",".",".","1"],[".",".",".","7",".",".",".",".","."],[".",".",".","5",".",".",".",".","."],[".",".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".",".","."]]
print(s.isValidSudoku(brd))
print(s.isValidSudoku(brd2))
print(s.isValidSudoku(brd3))

