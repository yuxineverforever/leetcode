/*
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 *
 *
 *
 */

/*
 * 方法二中，之所以要使用临时变量，是因为如果直接合并到数组 nums1\textit{nums}_1nums1​ 中，nums1\textit{nums}_1nums1​ 中的元素可能会在取出之前被覆盖。那么如何直接避免覆盖 nums1\textit{nums}_1nums1​ 中的元素呢？观察可知，nums1\textit{nums}_1nums1​ 的后半部分是空的，可以直接覆盖而不会影响结果。因此可以指针设置为从后向前遍历，每次取两者之中的较大者放进 nums1\textit{nums}_1nums1​ 的最后面。

严格来说，在此遍历过程中的任意一个时刻，nums1\textit{nums}_1nums1​ 数组中有 m−p1−1m-p_1-1m−p1​−1 个元素被放入 nums1\textit{nums}_1nums1​ 的后半部，nums2\textit{nums}_2nums2​ 数组中有 n−p2−1n-p_2-1n−p2​−1 个元素被放入 nums1\textit{nums}_1nums1​ 的后半部，而在指针 p1p_1p1​ 的后面，nums1\textit{nums}_1nums1​ 数组有 m+n−p1−1m+n-p_1-1m+n−p1​−1 个位置。由于

 *
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while (p1 >= 0 || p2 >= 0) {
            if (p1 == -1) {
                cur = nums2[p2--];
            } else if (p2 == -1) {
                cur = nums1[p1--];
            } else if (nums1[p1] > nums2[p2]) {
                cur = nums1[p1--];
            } else {
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }
};
