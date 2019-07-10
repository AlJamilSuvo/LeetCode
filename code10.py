class Solution(object):
    def isMatch(self, s, p):
        if len(s)==0 or len(p)==0:
            return len(s)==len(p)
        if len(p)>=2 and p[1]=='*':
            
                       




sol=Solution()
while True:
    s=input()
    p=input()
    print(str(sol.isMatch(s,p))) 