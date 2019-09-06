class Solution(object):
    def search(self, nums, target):
        return self.bSearch(nums,target,0,len(nums)-1)

    def bSearch(self,nums,target,left,right):
        if left>right:
            return -1
        mid=int((left+right)/2)
        if nums[mid]==target:
            return mid
        if nums[left]<=nums[mid] and nums[left]<=target and target<=nums[mid]:
            return self.bSearch(nums,target,left,mid-1)
        elif nums[mid]<=nums[right] and nums[mid]<=target and target<=nums[right]:
            return self.bSearch(nums,target,mid+1,right)
        elif nums[left]<=nums[mid]:
            return self.bSearch(nums,target,mid+1,right)
        else:
             return self.bSearch(nums,target,left,mid-1)


s=Solution()
nums=[4,5,6,7,0,1,2]
print(s.search(nums,0))
print(s.search(nums,1))
print(s.search(nums,3))


