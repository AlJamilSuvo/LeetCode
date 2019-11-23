'''
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
'''

class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        pt=0
        res=''
        i=len(a)-1
        j=len(b)-1
        while i>=0 or j>=0:
            cnt=0
            cnt=cnt+1 if i>=0 and a[i]=='1' else cnt
            cnt=cnt+1 if j>=0 and b[j]=='1' else cnt
            cnt+=pt
            res='1'+res if cnt%2==1 else '0'+res
            pt=1 if cnt>1 else 0
            i-=1
            j-=1
        if pt==1:
            res='1'+res
        return res

s=Solution()
print(s.addBinary('1','11'))