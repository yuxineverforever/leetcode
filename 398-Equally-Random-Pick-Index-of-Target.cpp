/**
 * Given an integer array nums with possible duplicates,
 * randomly output the index of a given target number.
 * You can assume that the given target number must exist in the array.
 *
Implement the Solution class:

    Solution(int[] nums) Initializes the object with the array nums.
        int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, then each index should have an equal probability of returning.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/random-pick-index
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 * Q: Given an integer array nums with possible duplicates,
 * randomly output the index of a given target number.
 * You can assume that the given target number must exist in the array.
 *
 * A:
 *
 */
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution2 {
public:
  Solution2(std::vector<int>& nums) {
    this->nums = nums;
  }

  int pick(int target) {
    int cnt = 0;
    int index = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == target) {
        cnt++;
        if (rand() % cnt == 0) {
          index = i;
          // 1/i prob
        }
      }
    }
    return index;
  }
private:
  std::vector<int> nums;
};

int main(){

  std::vector<int> nums{1, 2, 3, 3, 3};

  Solution2 s(nums);

  std::cout << "index: " << s.pick(3) << std::endl;

  return 0;
}

