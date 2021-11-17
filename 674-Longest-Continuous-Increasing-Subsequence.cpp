/***
 * Q: Given an unsorted array of integers nums,
 * return the length of the longest continuous increasing subsequence (i.e. subarray).
 * The subsequence must be strictly increasing.



A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is
 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].

 *
 *
 * A: one time traversal is enough.
 *
 */

class Solution {
public int findLengthOfLCIS(int[] nums) {
        if(nums.length <= 1)
            return nums.length;
        int ans = 1;
        int count = 1;
        for(int i=0;i<nums.length-1;i++) {
            if(nums[i+1] > nums[i]) {
                count++;
            } else {
                count = 1;
            }
            ans = count > ans ? count : ans;
        }
        return ans;
    }
}


