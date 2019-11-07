class Solution(object):
    def isValid(self, s):
        if len(s)%2!=0:
            return False
        stck=[]
        start_symbol=['(','{','[']
        end_sysmbol=[')','}',']']
        
        for current in s:
            if current in start_symbol:
                stck.append(current)
            else:
                if len(stck)==0 or start_symbol[end_sysmbol.index(current)]!=stck.pop():
                    return False
        return len(stck)==0
s=Solution()
print(s.isValid(')('))
        