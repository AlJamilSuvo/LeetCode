class Solution(object):
    def intToRoman(self, num):
        index=[1000,900,500,400,100,90,50,40,10,9,5,4,1]
        rm=['M','CM','D','CD','C','XC','L','XL','X','IX','V','IV','I']
        res=''
        while num>0:
            for i in range(0,len(index)):
                if num>=index[i]:
                    res=res+rm[i]
                    num-=index[i]
                    break

        return res

s=Solution()
print(s.intToRoman(20))