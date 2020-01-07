class Solution(object):
    def isInterleave(self, s1, s2, s3):
        self.map=dict()
        if len(s1)+len(s2) != len(s3):
            return False
        else:
            return self.checklInterleave(s1, s2, s3, 0, 0, 0)

    def checklInterleave(self, s1, s2, s3, i1, i2, i3):
        print(s1[i1:],s2[i2:],s3[i3:])
        if len(s1) == i1 and len(s2) == i2 and len(s3) == i3:
            return True
        if i1<len(s1) and s1[i1]==s3[i3] and self.checklInterleave(s1,s2,s3,i1+1,i2,i3+1):
            return True
        elif i2<len(s2) and s2[i2]==s3[i3] and self.checklInterleave(s1,s2,s3,i1,i2+1,i3+1):
            return True
        else:
            return False
        
s=Solution()
s1='a'
s2=''
s3='a'
print(s.isInterleave(s1,s2,s3))
        
