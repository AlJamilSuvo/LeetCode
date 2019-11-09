'''
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

'''

class Solution(object):
    def generateMatrix(self, n):
        current_point=pnt(0,0)
        direction=pnt(1,0)
        directionChangeCnt=1
        limit=n
        current_value=1
        matrix=[[0 for _ in range(n)] for __ in range(n)]
        while limit>0:
            for _ in range(limit):
                matrix[current_point.y][current_point.x]=current_value
                current_point+=direction
                current_value+=1
            current_point-=direction
            directionChangeCnt+=1
            direction=direction.rotatedClockWise90()
            current_point+=direction
            if directionChangeCnt==2:
                directionChangeCnt=0
                limit-=1
        return matrix
class pnt:
    def __init__(self,x,y):
        self.x=x
        self.y=y
    def __add__(self,o):
        return pnt(self.x+o.x,self.y+o.y)
    def __sub__(self,o):
        return pnt(self.x-o.x,self.y-o.y)
    def rotatedClockWise90(self):
        nx=self.x*0-self.y*1
        ny=self.x*1+self.y*0
        return pnt(nx,ny)
    def __str__(self):
        return '('+str(self.x)+','+str(self.y)+')'
s=Solution()
print(s.generateMatrix(3))