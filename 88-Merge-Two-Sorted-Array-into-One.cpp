/**
 * Q:
 * You are given two integer arrays [nums1] and [nums2],
 * sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.

 * The final sorted array should not be returned by the function,
 * but instead be stored inside the array [nums1].
 * To accommodate this, nums1 has a length of m + n,
 * where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored.
 * nums2 has a length of n.
 *
 * A: merge them from end to beginning.
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/
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
