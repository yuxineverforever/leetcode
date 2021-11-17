/**
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
   You must write an algorithm that runs in O(n) time.

   来源：力扣（LeetCode）
   链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
   著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

   A:
   hash table to store all the elements.
 *
 *
 */
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashTable;
        for (auto& n:nums){
            hashTable.insert(n);
        }
        int maxLen =1;
        for (auto& n : nums){
            if (hashTable.find(n-1) == hashTable.end()){
                int curr = n+1;
                int length = 1;
                while (hashTable.find(curr) != hashTable.end()){
                    curr++;
                    length++;
                }
                maxLen = std::max(maxLen,length);
            }
        }
        return maxLen;
    }
};