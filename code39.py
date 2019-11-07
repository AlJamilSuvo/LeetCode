class Solution(object):
    def combinationSum(self, candidates, target):
        self.dp=dict()
        self.findCombination(candidates,target)
        return self.dp[target]
    def findCombination(self,candidates,target):
        if target<0:
            return []
        elif target==0:
            return [[]]
        elif target not in self.dp.keys():
            self.dp[target]=[]
            alReadyFoundSet=set()
            for val in candidates:
                res=self.findCombination(candidates,target-val)
                for r in res:
                    newCombination=[val]
                    for fVal in r:
                        newCombination.append(fVal)
                    newCombination.sort()
                    if str(newCombination) not in alReadyFoundSet:
                        self.dp[target].append(newCombination)
                        alReadyFoundSet.add(str(newCombination))
        return self.dp[target]                
       

s=Solution()
print(s.combinationSum([2,3,5],8))