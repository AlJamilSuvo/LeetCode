import numpy as np
class Solution(object):
    def twoSum(self, nums, target):
        np_data=np.array(nums)
        for n in np_data:
            if (target-n) in np_data and target-n!=n:
                i,=np.where(np_data==n)
                j,=np.where(np_data==target-n)
                return[i[0],j[0]]
            elif target-n in np_data and target-n==n:
                i,=np.where(np_data==n)
                if len(list(i))>1:
                    return [i[0],i[1]]
