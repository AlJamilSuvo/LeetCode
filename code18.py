class Solution(object):
    def fourSum(self, nums, target):
        nums.sort()
        mp={}
        res=[]
        for i in range(0,len(nums)-3):
            for j in range(i+1,len(nums)-2):
                l=j+1
                r=len(nums)-1
                while l<r:
                    sm=nums[i]+nums[j]+nums[l]+nums[r]
                    if sm==target:
                        if (nums[i],nums[j],nums[l],nums[r]) not in mp:
                            res.append([nums[i],nums[j],nums[l],nums[r]])
                            mp[(nums[i],nums[j],nums[l],nums[r])]=1
                    if sm<target:
                        l+=1
                    else:
                        r-=1
        return res
s=Solution()
print(s.fourSum([0,0,0,0],0))

                
        