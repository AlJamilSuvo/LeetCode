class Solution(object):
    def nextPermutation(self, nums):
      for i in range(len(nums)-1,-1,-1):
        indx=-1
        minVal=10
        for j in range(0,len(nums)):
          if nums[j]>nums[i] and nums[j]<minVal:
            indx=j
            minVal=nums[j]
        if indx!=-1:
          temp=nums[i]
          nums[i]=nums[indx]
          nums[indx]=temp
          return
      nums.reverse()
      return

s=Solution()
lst=[1,2,3,4]
s.nextPermutation(lst)
print(lst)
