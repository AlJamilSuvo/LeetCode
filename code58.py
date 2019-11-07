class Solution(object):
    def lengthOfLastWord(self, s):
        l=0
        flag=False
        for ch in s:
            if ch==' ':
                flag=True
            elif flag:
                flag=False
                l=1
            else:
                l+=1
        return l
s=Solution()
print(s.lengthOfLastWord('Hello World'))
print(s.lengthOfLastWord('Hello'))
print(s.lengthOfLastWord('Hello  '))


    