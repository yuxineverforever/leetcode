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