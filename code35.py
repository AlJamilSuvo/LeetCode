class Solution(object):
    def searchInsert(self, nums, target):
        startIndex = self.firstIndex(nums,target,0,len(nums)-1)
        return startIndex
    def firstIndex(self,nums,target,lo,hi):
        if lo==hi and (nums[lo]==target or nums[lo]>target) or lo>hi:
            return lo
        elif lo==hi:
            return hi+1
        mid=int((lo+hi)/2)
        if target>nums[mid]:
            return self.firstIndex(nums,target,mid+1,hi)
        else:
            return self.firstIndex(nums,target,lo,mid)
s=Solution()
nums=[1,3,5,6]
print(s.searchInsert(nums,5))
print(s.searchInsert(nums,2))
print(s.searchInsert(nums,7))
print(s.searchInsert(nums,0))
print(s.searchInsert(nums,6))
lst=[]
print(s.searchInsert(lst,11))
