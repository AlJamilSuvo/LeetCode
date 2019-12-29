'''
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.

'''

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==0:
            return 0
        pointer=0
        current=nums[0]
        current_cnt=0
        for num in nums:
            if num==current:
                if current_cnt<2:
                    nums[pointer]=num
                    pointer+=1
                    current_cnt+=1
            else:
                nums[pointer]=num
                pointer+=1
                current=num
                current_cnt=1
        return pointer
s=Solution()
lst=[0,0,1,1,1,1,2,3,3]
print(s.removeDuplicates(lst))
print(lst)
        