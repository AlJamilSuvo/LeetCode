class Solution(object):
    def romanToInt(self, s):
        bases=[1000,900,500,400,100,90,50,40,10,9,5,4,1]
        symbols=['M','CM','D','CD','C','XC','L','XL','X','IX','V','IV','I']
        value=0
        while len(s)>0:
            for i in range(0,len(bases)):
                if s.startswith(symbols[i]):
                    value=value+bases[i]
                    s=s[len(symbols[i]):]
                    break
        return value
s=Solution()
print(s.romanToInt('XX'))
