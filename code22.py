class Solution(object):
    def generateParenthesis(self, n):
        return list(self.generate(n),[])
    def generate(self,n,results):
        if n==1:
            return set(['()'])
        else:
            lst=self.generate(n-1)
            print(lst)
            newLst=[]
            for res in lst:
                newLst.append('('+res+')')
                newLst.append('()'+res)
                newLst.append(res+'()')
            return set(newLst)
s=Solution()
print(s.generateParenthesis(4))
