class Solution(object):
    def permute(self, nums):
        self.ans=[]
        self.gen_permutation([],nums)
        return self.ans
    def gen_permutation(self,current,remaining):
        if len(remaining)==0:
            self.ans.append(current)
        else:
            for i in range(len(remaining)):
                self.gen_permutation(current+[remaining[i]],remaining[:i]+remaining[i+1:])


s=Solution()
print(s.permute([1,2,3]))