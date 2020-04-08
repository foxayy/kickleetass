class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        //找出算中位数需要的两个数，这里把奇偶数都统一了，用两个数之和除以2
        int prek = (len1 + len2 + 1) / 2;
        int k = (len1 + len2 + 2) / 2;
        return (get_key(nums1, 0, len1 - 1, nums2, 0, len2 - 1, prek) + get_key(nums1, 0, len1 - 1, nums2, 0, len2 - 1, k)) * 0.5;
    }

private:
    int get_key(vector<int>& nums1, int l1, int r1, vector<int>& nums2, int l2, int r2, int k) 
    {
        int len1 = r1 - l1 + 1;
        int len2 = r2 - l2 + 1;
        //为了下一个if判断只判断len1，使得短的序列一定是nums1序列
        if(len1 > len2) {
            return get_key(nums2, l2, r2, nums1, l1, r1, k);
        }
        if(0 == len1) {
            return nums2[l2 + k - 1];
        }
        if(1 == k) {
            return min(nums1[l1], nums2[l2]);
        }
        //判断删除到的节点
        int i = l1 + min(len1, k/2) - 1;
        int j = l2 + min(len2, k/2) - 1;
        if(nums1[i] > nums2[j]) {
            return get_key(nums1, l1, r1, nums2, j + 1, r2, k - (j - l2 + 1));
        } else {
            return get_key(nums1, i + 1, r1, nums2, l2, r2, k - (i - l1 + 1));
        }
    }
};
