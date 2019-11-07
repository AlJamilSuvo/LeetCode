class Solution(object):
    def threeSumClosest(self, nums, target):
        nums.sort()
        res=0
        minDiff=1e10
        for i in range(0,len(nums)-2):
            l=i+1
            r=len(nums)-1
            while l<r:
                s=nums[i]+nums[l]+nums[r]
                diff=abs(s-target)
                if diff<minDiff:
                    minDiff=diff
                    res=s
                if s<target:
                    l+=1
                else:
                    r-=1
            if res>target:
                return res
        return res

s=Solution()
print(s.threeSumClosest([-1, 2, 1, -4],100))