class Solution(object):
    def generateParenthesis(self, n):
        self.results=set()

        def back(opn,clos,ptrn):
            if opn==0 and clos==0:
                self.results.add(ptrn)
            if opn>0:
                back(opn-1,clos,ptrn+'(')
            if clos>opn:
                back(opn,clos-1,ptrn+')')
        back(n,n,'')
        return list(self.results)
s=Solution()
print(s.generateParenthesis(4))