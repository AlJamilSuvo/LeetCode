class Solution(object):
    def maxArea(self, height):
        left=0
        right=len(height)-1
        maxArea=0
        while left<right:
            maxArea=max(maxArea,min(height[left],height[right])*(right-left))
            if height[left]>height[right]:
                right-=1
            else:
                left+=1
        return maxArea


s=Solution()       
h=[i for i in range(0,15000)]
print(s.maxArea(h))