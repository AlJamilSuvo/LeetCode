class Solution(object):
    def jump(self, nums):
        current=0
        jump_cnt=0
        target=len(nums)-1
        while  True:
            if current>=target:
                return jump_cnt
            current_max_jumps=nums[current]
            max_index=0
            next_max_jumps=-1
            for index in range(current+1,current+current_max_jumps+1):
                if index>=target:
                    return jump_cnt+1
                if nums[index]+index>=next_max_jumps:
                    max_index=index
                    next_max_jumps=nums[index]+index
            current=max_index
            jump_cnt+=1
s=Solution()
print(s.jump([10,9,8,7,6,5,4,3,2,1,1,0]))
