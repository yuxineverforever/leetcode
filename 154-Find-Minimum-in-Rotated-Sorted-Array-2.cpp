
/**
 *
 * Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

    [4,5,6,7,0,1,4] if it was rotated 4 times.
    [0,1,4,4,5,6,7] if it was rotated 7 times.

Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.

https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/

 设置 left, right 指针在 nums 数组两端，mid 为每次二分的中点：

    当 nums[mid] > nums[right]时，mid 一定在第 1 个排序数组中，iii 一定满足 mid < i <= right，因此执行 left = mid + 1；
    当 nums[mid] < nums[right] 时，mid 一定在第 2 个排序数组中，iii 一定满足 left < i <= mid，因此执行 right = mid；
    当 nums[mid] == nums[right] 时，是此题对比 153题 的难点（原因是此题中数组的元素可重复，难以判断分界点 iii 指针区间）；
        例如 [1,0,1,1,1][1, 0, 1, 1, 1][1,0,1,1,1] 和 [1,1,1,0,1][1, 1, 1, 0, 1][1,1,1,0,1] ，在 left = 0, right = 4, mid = 2 时，无法判断 midmidmid 在哪个排序数组中。
        我们采用 right = right - 1 解决此问题，证明：
            此操作不会使数组越界：因为迭代条件保证了 right > left >= 0；
            此操作不会使最小值丢失：假设 nums[right]是最小值，有两种情况：
                若 nums[right] 是唯一最小值：那就不可能满足判断条件 nums[mid] == nums[right]，因为 mid < right（left != right 且 mid = (left + right) // 2 向下取整）；
                若 nums[right] 不是唯一最小值，由于 mid < right 而 nums[mid] == nums[right]，即还有最小值存在于 [left,right−1][left, right - 1][left,right−1] 区间，因此不会丢失最小值。

作者：jyd
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/154-find-minimum-in-rotated-sorted-array-ii-by-jyd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 *
 */


class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high]) {
                high = pivot;
            }
            else if (nums[pivot] > nums[high]) {
                low = pivot + 1;
            }
            else {
                high -= 1;
            }
        }
        return nums[low];

    }
};