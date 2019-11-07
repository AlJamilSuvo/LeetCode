from math import log10
class Solution(object):
    def isPalindrome(self, x):

        dgt=log10(x)
        if x<0 : 
            return False
        else if x<10:
            return True
        mirror=0
        while x>mirror:
            mirror=mirror*10+x%10
            x=x//10
        print(x)
        print(mirror)
        return (dgt%2==0 and x==mirror) or (dgt%2==0 and mirror//10==x)
s=Solution()
print(s.isPalindrome(3))
print(s.isPalindrome(10))
print(s.isPalindrome(313))
print(s.isPalindrome(1221))



        
        