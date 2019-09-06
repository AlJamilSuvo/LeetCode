class Solution(object):
    def isMatch(self, s, p):
        self.dp=dict()
        return self.checkInMatch(s,p,0,0)

    def checkInMatch(self,s,p,i,j):
        if i==len(s) and j==len(p):
            return True
        elif j==len(p):
            return False
        elif i==len(s):
            for pp in p[j:]:
                if pp!='*':
                    return False
            return True
        if p[j]=='*':
            if (i+1,j) not in self.dp.keys():
                check1=self.checkInMatch(s,p,i+1,j)
                self.dp[(i+1,j)]=check1
            else:
                check1=self.dp[(i+1,j)]                
            
            if (i+1,j+1) not in self.dp.keys():
                check2=self.checkInMatch(s,p,i+1,j+1)
                self.dp[(i+1,j+1)]=check2
            else:
                check2=self.dp[(i+1,j+1)]

            if (i,j+1) not in self.dp.keys():
                check3=self.checkInMatch(s,p,i,j+1)
                self.dp[(i,j+1)]=check3
            else:
                check3=self.dp[(i,j+1)]


            return check1 or check2 or check3
        elif p[j]=='?' or p[j]==s[i] :
            if (i+1,j+1) not in self.dp.keys():
                check2=self.checkInMatch(s,p,i+1,j+1)
                self.dp[(i+1,j+1)]=check2
            else:
                check2=self.dp[(i+1,j+1)]
            return check2
        else:
            return False


s=Solution()
print(s.isMatch("a","a*"))
