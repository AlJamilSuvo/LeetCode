class Solution(object):
    def isMatch(self, s, p):
        self.dp=dict()
        return self.checkInMatch(s,p)

    def checkInMatch(self,s,p):
        if s=='' and (p=='' or (len(set(p))==1 and p[0]=='*')):
            return True
        elif s=='' or p=='':
            return False
        elif s+'.'+p in self.dp.keys():
            return self.dp[s+'.'+p]
        elif p[0]=='*':
            flag10=self.dp[s[1:]+'.'+p] if s[1:]+'.'+p in self.dp.keys() else self.checkInMatch(s[1:],p)
            flag01=self.dp[s+'.'+p[1:]] if s+'.'+p[1:] in self.dp.keys() else self.checkInMatch(s,p[1:])
            flag11=self.dp[s[1:]+'.'+p[1:]] if s[1:]+'.'+p[1:] in self.dp.keys() else self.checkInMatch(s[1:],p[1:])
            self.dp[s[1:]+'.'+p]=flag01
            self.dp[s+'.'+p[1:]]=flag10
            self.dp[s[1:]+'.'+p[1:]]=flag11
            self.dp[s+'.'+p]=flag01 or flag10 or flag11
            return self.dp[s+'.'+p]
        elif p[0]=='?' or p[0]==s[0]:
            flag11=self.dp[s[1:]+'.'+p[1:]] if s[1:]+'.'+p[1:] in self.dp.keys() else self.checkInMatch(s[1:],p[1:])
            self.dp[s[1:]+'.'+p[1:]]=flag11
            self.dp[s+'.'+p]=flag11
            return flag11
        else:
            self.dp[s+'.'+p]=False
            return False


s=Solution()
print(s.isMatch('aa','a'))
print(s.isMatch('aa','a*'))
print(s.isMatch('aa','*'))
print(s.isMatch('aa','*a'))
print(s.isMatch('aa','*aa'))
print(s.isMatch("aaabababaaabaababbbaaaabbbbbbabbbbabbbabbaabbababab","*ab***ba**b*b*aaab*b"))
