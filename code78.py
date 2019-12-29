'''

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]


'''
import copy

class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res=[]
        self.find_power_set([],nums,res)
        return res
    def find_power_set(self,taken_nums,remaining_nums,res):
        if len(remaining_nums)==0:
            res.append(copy.deepcopy(taken_nums))
        for num in remaining_nums:
            tn=copy.deepcopy(taken_nums)
            rn=copy.deepcopy(remaining_nums)
            rn.remove(num)
            tn.append(num)
            self.find_power_set(taken_nums,rn,res)
            self.find_power_set(tn,rn,res)
s=Solution()
print(s.subsets([1,2]))