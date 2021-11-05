/**
Q: You are given an array of non-overlapping intervals intervals where intervals[i] = [start_i, end_i]
represent the start and the end of the i-th interval and intervals is sorted in ascending order by start_i.

You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals

(merge overlapping intervals if necessary).

Return intervals after the insertion.


A: simulating

 https://leetcode-cn.com/problems/insert-interval/
**/

// 如果 ri<leftr_i < \textit{left}ri<left，说明 [li,ri][l_i, r_i][li,ri] 与 SSS 不重叠并且在其左侧，我们可以直接将 [li,ri][l_i, r_i][li,ri] 加入答案；
//
//如果 li>rightl_i > \textit{right}li>right，说明 [li,ri][l_i, r_i][li,ri] 与 SSS 不重叠并且在其右侧，我们可以直接将 [li,ri][l_i, r_i][li,ri] 加入答案；
//
//如果上面两种情况均不满足，说明 [li,ri][l_i, r_i][li,ri] 与 SSS 重叠，我们无需将 [li,ri][l_i, r_i][li,ri] 加入答案。此时，我们需要将 SSS 与 [li,ri][l_i, r_i][li,ri] 合并，即将 SSS 更新为其与 [li,ri][l_i, r_i][li,ri] 的并集。

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int left = newInterval[0];

        int right = newInterval[1];

        bool placed = false;

        vector<vector<int>> ans;

        for (const auto& interval: intervals) {
            if (interval[0] > right) {
                // 在插入区间的右侧且无交集
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left) {
                // 在插入区间的左侧且无交集
                ans.push_back(interval);
            }
            else {
                // 与插入区间有交集，计算它们的并集
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
};
