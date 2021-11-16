/**
Q:
  Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
  If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
  The replacement must be in place and use only constant extra memory.

A:
  1. Find the point (a[i]<a[i+1]) by iterating from last. This is our [index1].
  2. If there is no break point that means array is in descending order. So, simply reverse full array.
  3. Else again iterate from last and find the element who is great than a[index1]. Store it as [index2].
  4. Swap the 2 elements at [index1] and [index2].
  5. Finally reverse the array from [index1+1], so that we get the minimum number. Which means the next permutation.
**/

class Solution {
public:
  void nextPermutation(vector<int>& nums) {

    int i, j;
    int n= nums.size();
    int a=0;

    for(i=n-2; i>=0; i--){

      if(nums[i]<nums[i+1]){
        break;
      }

    }

    if(i<0)
      reverse(nums.begin(), nums.end());
    else {

      for(j=n-1; j>=0; j--) {
        if(nums[i]<nums[j]){
          break;
        }
      }
      swap(nums[i], nums[j]);
      reverse(nums.begin()+i+1, nums.end());
    }
  }
};
