class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        self.x=nums1 if len(nums1)<=len(nums2) else nums2
        self.y=nums2 if len(nums1)<=len(nums2) else nums1
        self.lenX=len(self.x)
        self.lenY=len(self.y)
        self.leftX=0
        self.rightX=self.lenX
        self.calculateParam()
        flag=self.check()
        while flag!=0:
            if flag==-1:
                self.rightX=self.midX-1
            else :
                self.leftX=self.midX+1
            self.calculateParam()
            flag=self.check()
        return self.findMedian()
    def calculateParam(self):
        self.midX=int((self.leftX+self.rightX)/2)
        self.midY=int((self.lenX+self.lenY+1)/2)-self.midX
        self.valueLeftX= self.x[self.midX-1] if self.midX>0 else -10000000
        self.valueRightX= self.x[self.midX] if self.midX<self.lenX else 10000000
        self.valueLeftY= self.y[self.midY-1] if self.midY>0 else -10000000
        self.valueRightY= self.y[self.midY] if self.midY<self.lenY else 10000000
    def check(self):
        if self.valueLeftX<=self.valueRightY and self.valueLeftY<=self.valueRightX:
            return 0
        if self.valueLeftX>self.valueRightY:
            return -1
        if self.valueRightX<self.valueLeftY:
            return 1
    def findMedian(self):
        if(self.lenX+self.lenY)%2==0:
            return float(max(self.valueLeftX,self.valueLeftY)+min(self.valueRightX,self.valueRightY))/2
        else:
            return max(self.valueLeftX,self.valueLeftY)

s=Solution()
nums1 = [1,2,5]
nums2 = [3,4]
print(s.findMedianSortedArrays(nums1,nums2))


        


