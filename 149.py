'''
Given an array of points where points[i] = [xi, yi] represents a point on
the X-Y plane, return the maximum number of points that lie on the same
straight line.

https://leetcode.com/problems/max-points-on-a-line/

'''


class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        lines=[]

        point_count=[]

        for i in range(0, len(points)-1):
            for j in range(i+1, len(points)):
                
     

