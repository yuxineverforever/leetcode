/**
Q: Given an array of intervals where intervals[i] = [start_i, end_i],
 merge all overlapping intervals,
 and return an array of the non-overlapping intervals that cover all the intervals in the input.

A: first sort all the intervals in the array with their left start value.
   Then we have the claim: all the consecutive intervals can
    1. be merged
    2. They belong to different non-overlapping intervals.

    https://leetcode-cn.com/problems/merge-intervals/
 **/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }

        std::sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        for (int i = 0; i < intervals.size(); ++i) {

            int L = intervals[i][0], R = intervals[i][1];

            if (!merged.size() || merged.back()[1] < L) {
                //belong to different non-overlapping intervals.
                merged.push_back({L, R});

            } else {

                //merged
                merged.back()[1] = max(merged.back()[1], R);

            }
        }
        return merged;
    }
};