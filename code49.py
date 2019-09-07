class Solution(object):
    def groupAnagrams(self, strs):
        ans=dict()
        for st in strs:
            hash=self.getHash(st)
            if hash in ans:
                ans[hash].append(st)
            else:
                ans[hash]=[st]
        return list(ans.values())

    def getHash(self,st):
        cnt=[0 for i in range(26)]
        for s in st:
            i=ord(s)-ord('a')
            cnt[i]+=1
        return str(cnt)

        
s=Solution()
print(s.groupAnagrams( ["eat", "tea", "tan", "ate", "nat", "bat"]))