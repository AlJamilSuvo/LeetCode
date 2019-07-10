class Solution(object):
    def longestCommonPrefix(self, strs):
        if len(strs)==0:
            return ''
        length=0
        for i in range(0,len(strs[0])):
            current_char=strs[0][i]
            is_ok=True
            for st in strs:
                if len(st)<=i or st[i]!=current_char:
                    is_ok=False
                    break
            if not is_ok:
                break
            length=length+1
        return strs[0][0:length]
s=Solution()
print(s.longestCommonPrefix(["dog","racecar","car"]))