'''
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
'''



class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """

        self.lx=0
        self.ty=0
        self.by=len(matrix)-1
        if(self.by<0):
            return []
        self.rx=len(matrix[0])-1
        self.dx=1
        self.dy=0

        self.startX=0
        self.endX=0
        self.startY=0
        self.endY=0
        self.setStartAndEndPoint()
        x=self.startX
        y=self.startY
        self.ans=[]
        while True:
            self.ans.append(matrix[y][x])
            if x==self.endX and y==self.endY:
                self.resetBorderPoint()
                if self.lx==self.rx and self.ty==self.by:
                    self.ans.append(matrix[self.ty][self.lx])
                    return self.ans
                elif self.lx>self.rx or self.ty>self.by:
                    return self.ans
                self.rotate()
                self.setStartAndEndPoint()
                x=self.startX
                y=self.startY
            else:
                x+=self.dx
                y+=self.dy



    def rotate(self):
        px=-self.dy
        py=self.dx
        self.dx=px
        self.dy=py
    
    def setStartAndEndPoint(self):
        if self.dx==1 and self.dy==0:
            self.startX=self.lx
            self.endX=self.rx
            self.startY=self.ty
            self.endY=self.ty
        elif self.dx==-1 and self.dy==0:
            self.startX=self.rx
            self.endX=self.lx
            self.startY=self.by
            self.endY=self.by
        elif self.dx==0 and self.dy==1:
            self.startX=self.rx
            self.endX=self.rx
            self.startY=self.ty
            self.endY=self.by
        elif self.dx==0 and self.dy==-1:
            self.startX=self.lx
            self.endX=self.lx
            self.startY=self.by
            self.endY=self.ty

    def resetBorderPoint(self):
        if self.dx==1 and self.dy==0:
            self.ty+=1
        elif self.dx==-1 and self.dy==0:
            self.by-=1
        elif self.dx==0 and self.dy==1:
            self.rx-=1
        elif self.dx==0 and self.dy==-1:
            self.lx+=1

s=Solution()
a=[[ 1, 2, 3 ],[ 4, 5, 6 ],[ 7, 8, 9 ]]
b=[[1, 2, 3, 4],[5, 6, 7, 8],[9,10,11,12]]
c=[]
d=[[1,2,3,4,5,6,7]]
e=[[1],[2],[3],[4],[5],[5],[6],[7]]
print(s.spiralOrder(a))
print(s.spiralOrder(b))
print(s.spiralOrder(c))
print(s.spiralOrder(d))
print(s.spiralOrder(e))