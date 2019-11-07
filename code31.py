'''
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
'''

class Solution(object):
    def nextPermutation(self, nums):
        p=len(nums)-2
        if len(nums)==1:
            return nums
        for i in range(len(nums)-2,-1,-1):
            if nums[i]<nums[i+1]:
                break
            p-=1
        if p<0:
            nums.reverse()
            return
        val=nums[p]
        k=len(nums)
        
        for i in range(len(nums)-1,-1,-1):
            if nums[i]>val:
                k=i
                break
        nums[p]=nums[k]
        nums[k]=val
        ln=len(nums)
        rev_len=len(nums)-p-1
        for i in range(int(rev_len/2)):
            tmp=nums[p+1+i]
            nums[p+1+i]=nums[ln-1-i]
            nums[ln-i-1]=tmp
s=Solution()
n=[1,3,2]
n=[1,2,3]
s.nextPermutation(n)
print(n)