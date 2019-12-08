class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        nums1=nums1[:m]
        nums2=nums2[:n]

        i=0
        j=0
        while j<n:
            print(i,j,nums1)
            if i>
            if i<m and  nums2[j]<nums1[i] :
                nums1.insert(i,nums2[j])
                j+=1
            i+=1
s=Solution()
print(s.merge([1,2,3,0,0,0],3,[2,5,6],3))
