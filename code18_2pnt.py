class Solution(object):
    def fourSum(self, nums, target):
        results=[]
        preResult=[]
        self.generalSum(nums,4,preResult,results,target)
        return results

    def generalSum(self,nums,sumCnt,preResult,results,target):
        if sumCnt<2 or len(nums) <sumCnt:
            return
        if sumCnt==2:
            left=0
            right=len(nums)-1
            while left<right:
                a=nums[left]
                b=nums[right]
                s=a+b
                if s==target:
                    results.append(preResult+[a,b])
                    left+=1
                    right-=1
                    while nums[left]==a:
                        left+=1
                    while nums[right]==b:
                        right-=1
                elif s<target:
                    left+=1
                else:
                    right-=1
        else:
            for i in range(0,len(nums)-sumCnt+1):
                if i==0 or (i>0 and nums[i-1]!=nums[i]):
                    self.generalSum(nums[i+1:],sumCnt-1,[[nums[i]]]+preResult,results,target-nums[i])



                

s=Solution()
print(s.fourSum([1, 0, -1, 0, -2, 2],0))