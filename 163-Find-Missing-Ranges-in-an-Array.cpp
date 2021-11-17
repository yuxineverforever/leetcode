/**
 * Q: Given a range [low, upper],
 * cover all the numbers not appearing in the provided array [nums].
 *
 *
 * A: just simple one time traversal.
https://leetcode-cn.com/problems/missing-ranges/
 *
 */
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        long l = (long)lower - 1;
        for(int iter : nums){

            if(iter > upper)
                break;

            if(iter - l == 2){
                ans.push_back(to_string(l + 1));
            } else if(iter - l > 2){
                ans.push_back(to_string(l + 1) + "->" + to_string(iter - 1));
            }

            l = iter;
        }
        if(upper - l == 1){
            ans.push_back(to_string(upper));
        }
        else if(upper - l > 1){
            ans.push_back(to_string(l + 1) + "->" + to_string(upper));
        }
        return ans;
    }
};