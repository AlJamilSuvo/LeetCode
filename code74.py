'''
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false

'''

class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m=len(matrix)
        if m==0:
            return False
        n=len(matrix[0])
        if n==0:
            return False
        listIdx=self.search_list(matrix,target,0,m-1,n)
        if listIdx==-1:
            return False
        return self.search_in_list(matrix,target,0,n-1,listIdx)

    def search_list(self,matrix,target,left,right,n):
        mid=int((left+right)/2)
        if target>=matrix[mid][0] and target<=matrix[mid][n-1]:
            return mid
        if left==right:
            return -1
        if target>matrix[mid][0]:
            return self.search_list(matrix,target,mid+1,right,n)
        else :
            return self.search_list(matrix,target,left,mid,n)
    def search_in_list(self,matrix,target,left,right,m):
        mid=int((left+right)/2)
        if matrix[m][mid]==target:
            return True
        if left==right:
            return False
        if target>matrix[m][mid]:
            return self.search_in_list(matrix,target,mid+1,right,m)
        else:
            return self.search_in_list(matrix,target,left,mid,m)

s=Solution()
matrix= [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
print(s.searchMatrix(matrix,-10))       
print(s.searchMatrix(matrix,3))       
print(s.searchMatrix(matrix,11))       
print(s.searchMatrix(matrix,24))       
print(s.searchMatrix(matrix,100))       