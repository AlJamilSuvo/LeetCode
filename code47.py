class Solution(object):
    def permuteUnique(self, nums):
        self.ans=[]
        self.gen_permutation([],nums)
        return self.ans
        
    def gen_permutation(self,current,remaining):
        if len(remaining)==0:
            self.ans.append(current)
        else:
            d=[]
            for i in range(len(remaining)):
                if remaining[i] in d:
                    continue
                self.gen_permutation(current+[remaining[i]],remaining[:i]+remaining[i+1:])
                d.append(remaining[i])

s=Solution()
print(s.permuteUnique([1,1,3]))