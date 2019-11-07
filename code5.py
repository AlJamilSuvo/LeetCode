class Solution(object):
    def longestPalindrome(self, s):
        self.getLongestPalindromeCenter(s)
        return s
    
    def getLongestPalindromeCenter(self,s):
        formatedStr=self.createNewString(s)
        c=0
        v=0
        l=len(formatedStr)
        p=[0 for i  in range(len(formatedStr))]
        for i in range(0,len):
            mirror=c-(i-c)
            p[i]=p[mirror]
            j=i
            while c-(c-j)>=0 and formatedStr[j]==formatedStr[c-(c-j)]:
                j+=1
            p[i]+=c-j
            v=j


            



        print(formatedStr)

    def createNewString(self,s):
        newStr='#'
        for ch in s:
            newStr=newStr+ch+'#'
        return newStr


s=Solution()
s.longestPalindrome('abbc')
