'''
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?


https://leetcode.com/problems/single-number/


Solution :

Hashmap is a linear time solution but here it requires extra memory
for less memory xor is handy

lets elements are a, b, c, d, a, b, d

we know a ⊕ 0 = a
and a ⊕ a = 0


let perfrom  a ⊕ b ⊕ c ⊕ d ⊕ a ⊕ b ⊕ d

        =  a ⊕ a ⊕ b ⊕ b ⊕ d ⊕ d ⊕ c
        =    0   ⊕   0   ⊕   0   ⊕ c
        =  0 ⊕ c
        =   c

'''


class Solution(object):
    def singleNumber(self, nums):
        result = 0
        for num in nums:
            result = result ^ num
        return result


solution = Solution()
print(solution.singleNumber([2, 3, 4, 5, 7, 3, 2, 4, 5]))
