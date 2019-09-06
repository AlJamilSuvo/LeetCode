class Solution(object):
    def searchRange(self, nums, target):
        lo=self.lo_bSearch(nums,target,0,len(nums)-1)
        if lo==-1:
            return [-1,-1]
        else:
            return lo

    def lo_bSearch(self,nums,target,lo,hi):
        print(nums[lo:hi+1])
        if lo==hi and nums[lo]==target:
            return lo
        elif lo==hi:
            return -1
        mid=int((lo+hi)/2)
        if target==nums[mid] or target<nums[mid]:
            return self.lo_bSearch(nums,target,lo,mid)
        else:
            return self.lo_bSearch(nums,target,mid,hi)

s=Solution()
l=[5,7,7,8,8,10]
print(s.searchRange(l,7))
