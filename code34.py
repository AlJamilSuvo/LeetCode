class Solution(object):
    def searchRange(self, nums, target):
        startIndex = self.firstIndex(nums,target,0,len(nums)-1)
        if startIndex==-1:
            return [-1,-1]
        endIndex=self.lastIndex(nums,target,startIndex,len(nums)-1)
        return [startIndex,endIndex]
    def firstIndex(self,nums,target,lo,hi):
        if lo==hi and nums[lo]==target:
            return lo
        elif lo==hi or lo>hi:
            return -1
        mid=int((lo+hi)/2)
        if target>nums[mid]:
            return self.firstIndex(nums,target,mid+1,hi)
        else:
            return self.firstIndex(nums,target,lo,mid)

    def lastIndex(self,nums,target,lo,hi):
        if lo==hi and nums[lo]==target:
            return lo
        elif lo==hi:
            return -1
        mid=int((lo+hi)/2)+1
        if nums[mid]>target:
            return self.lastIndex(nums,target,lo,mid-1)
        else:
            return self.lastIndex(nums,target,mid,hi)        


s=Solution()
nums=[5,7,7,8,8,10]
print(s.searchRange(nums,7))
print(s.searchRange(nums,8))
print(s.searchRange(nums,10))
print(s.searchRange(nums,5))
print(s.searchRange(nums,6))
print(s.searchRange(nums,4))
print(s.searchRange(nums,11))
lst=[]
print(s.searchRange(lst,11))