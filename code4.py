class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        num=nums1+nums2
        list.sort(num)
        l=len(num)
        if l%2==1:
            return num[l//2]
        else:
            return (num[l/2-1]+num[l/2])/2
