/**
 * Q: You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.
 *
 *
 *
 * A: Binary Search
 *
 *我们将线性搜索转换为二分搜索是有意义的，它能加快我们的效率。为了使用二分搜索，我们需要查看中间的元素来判断我们的答案在中间，
 * 左边还是右边。我们的数组个数始终是奇数，因为有一个元素出现一次，其余元素出现两次。
 *
 **/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            bool halvesAreEven = (hi - mid) % 2 == 0;
            // mid element is the last one
            if (nums[mid + 1] == nums[mid]) {
                if (halvesAreEven) {
                    lo = mid + 2;
                } else {
                    hi = mid - 1;
                }
                // mid element is the first one
            } else if (nums[mid - 1] == nums[mid]) {
                if (halvesAreEven) {
                    hi = mid - 2;
                } else {
                    lo = mid + 1;
                }
            } else {
                // mid element is the one we are looking for.
                return nums[mid];
            }
        }
        return nums[lo];
    }
};