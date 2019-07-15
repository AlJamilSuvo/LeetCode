class Solution(object):
    def letterCombinations(self, digits):
        if len(digits)<1:
            return []
        st=97
        mp={}
        for i in range(2,10):
            lp=4 if i==7 or i==9 else 3
            lst=[]
            for _ in range(lp):
                lst.append(chr(st))
                st+=1
            mp[str(i)]=lst
        res=['']
        for d in range(len(digits)-1,-1,-1):
            newRes=[]
            for cmb in res:
                for ch in mp[digits[d]]:
                    newRes.append(ch+cmb)
            res=newRes
        return res
        
        
s=Solution()
print(len(s.letterCombinations("23986547")))
        