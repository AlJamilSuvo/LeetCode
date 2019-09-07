class Solution(object):
    def rotate(self, matrix):
        n=len(matrix)
        for i in range(n):
            for j in range(i):
                t=matrix[i][j]
                matrix[i][j]=matrix[j][i]
                matrix[j][i]=t
        