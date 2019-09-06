class Solution(object):
    def strStr(self, haystack, needle):
        if len(needle)==0:
            return 0
        hi=0
        ni=0
        si=0
        while hi<len(haystack):
            if haystack[hi]==needle[ni]:
                if ni==len(needle)-1:
                    return si
                elif ni==0:
                    si=hi
                ni+=1
            elif ni!=0:
                hi=si
                ni=0
            hi=hi+1
        return -1
s=Solution()
print(s.strStr('mississippi','issip'))