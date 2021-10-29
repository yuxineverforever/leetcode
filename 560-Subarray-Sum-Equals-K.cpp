/**
 *
 *
 * Given an array of integers nums and an integer k,
 * return the total number of continuous subarrays whose sum equals to k.
 *
 *
 * There are two cases:
 * 1. all positive numbers
 *
 * 2. part are positive, part are negative.
 *
 */
#include <vector>
#include <map>

class Solution {

public:
    int subarraySum(std::vector<int>& nums, int k) {
        int len = nums.size();
        int presum  = 0;
        int count = 0;
        std::map<int,int> hashMap;
        hashMap[0] = 1;
        for (int i = 0;i < len; i++){

          presum += nums[i];

          if (hashMap.find(presum - k)!= hashMap.end()){
            count += hashMap[presum - k];
          }

          if (hashMap.find(presum)==hashMap.end()){
              hashMap[presum] = 1;
          } else {
              hashMap[presum]++;
          }
        }
        return count;
    }
};