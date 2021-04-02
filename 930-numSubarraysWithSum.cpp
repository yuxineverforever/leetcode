// Leetcode 724
// Leetcode 1
// Leetcode 560
// Leetcode 1248
// Leetcode 974
// Leetcode 523
// Leetcode 930
#include <iostream>
#include <unordered_map>
#include <vector>

/**
 *  for (int i = 0; i < nums.length; i++) {
      presum[i+1] = nums[i] + presum[i];
 }
 */

class Solution {

public:

    int numSubarraysWithSum(std::vector<int>& A, int S) {

        int presum = 0;
        int counts = 0;
        std::unordered_map<int,int> hashTable;
        hashTable.insert({0,1});
        for (auto & ele: A){
            presum += ele;
            int num = hashTable.count(presum - S);
            if ( num != 0){
                counts += hashTable[presum - S];
            }
            int sum = hashTable.count(presum);
            if (sum!=0){
                hashTable[presum]++;
            } else {
                hashTable.insert({presum,1});
            }
        }
        return counts;
    }

};

int main(){
    std::vector<int> arr = {1,0,1,0,1};
    int S =2;
    Solution s;
    s.numSubarraysWithSum(arr,S);

}