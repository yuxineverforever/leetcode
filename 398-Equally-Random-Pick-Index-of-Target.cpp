/**
 *
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

