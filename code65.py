import re
class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s=s.strip()
        first_part=s
        second_part=''
        if 'e' in s:
            first_part=s[:s.index('e')]
            second_part=s[s.index('e'):]
        if first_part=='':
            return False
        pattern=r'^e(-|\+)?[0-9]+$'
        isOk=self.checkIfWithOutEPartOk(first_part)
        if second_part!='':
            x=re.match(pattern,second_part)
            isOk=isOk and x!=None
        return isOk

        

    def checkIfWithOutEPartOk(self,s):
        pattern=r'^(-|\+)?([0-9]*(\.[0-9]+))$|^(-|\+)?([0-9]+(\.[0-9]*)?)$'
        x=re.match(pattern,s)
        return x!=None



s=Solution()
while True:
    txt=raw_input()
    print(s.isNumber(txt))
