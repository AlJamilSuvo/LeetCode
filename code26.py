class Solution(object):
    def removeDuplicates(self, nums):
        i=0
        for j in range(0,len(nums)):
            if j==0 or nums[j-1] != nums[j]:
                nums[i]=nums[j]
                i+=1
        return i
        