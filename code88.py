class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        i=0
        j=0
        while j<n:
            if i>=m+j or nums2[j]<nums1[i]:
                del nums1[-1]
                nums1.insert(i,nums2[j])
                j+=1
            i+=1
        print(nums1)
s=Solution()
s.merge([1,2,3,0,0,0],3,[2,5,6],3)
