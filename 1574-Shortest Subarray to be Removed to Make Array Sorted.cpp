/**
 * Q:
 * Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.

A subarray is a contiguous subsequence of the array.

Return the length of the shortest subarray to remove.

 *
 * A:
 *
 */
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // 找到最左边开始递减的位置 i 有 arr[i-1] > arr[i]
        // 找到最右边的非递减的开始位置 j 有 arr[k] <= arr[k+1], any k >= j
        int left = 1, right = arr.size()-1, n = arr.size();
        while (left < n && arr[left-1] <= arr[left]) ++left;
        while (right-1 >= 0 && arr[right-1] <= arr[right]) --right;
        if (left > right) return 0; // 已经有序
        // 中间的子数组 arr[left:right] 肯定是要删除的，因为只能删除一个连续的子数组
        int ans = right;
        for (int i = 0; i < left; ++i) {
            int e = arr[i];
            int j = lower_bound(arr.begin()+right, arr.end(), e) - arr.begin();
            ans = min(ans, j-i-1);
        }
        return ans;
    }
};