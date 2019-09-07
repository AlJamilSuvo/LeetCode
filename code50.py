class Solution(object):
    def myPow(self, x, n):
        if n==0:
            return 1
        elif n==1:
            return x
        elif n<0:
          return 1/self.myPow(x,-1*n)
        else:
            v=self.myPow(x,int(n/2))
            if n%2==0:
                return v*v
            else:
                return v*v*x
        

s=Solution()
print(s.myPow(2,-3))