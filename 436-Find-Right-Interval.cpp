/**
 *
 * You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.

The right interval for an interval i is an interval j such that startj >= endi and startj is minimized.

Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-right-interval
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < intervals.size(); ++i) {
            arr.emplace_back(make_pair(intervals[i][0], i));
        }
        sort(arr.begin(), arr.end());
        vector<int> result;
        for (int i = 0; i < intervals.size(); ++i) {
            result.push_back(findFirstBig(arr, intervals[i][1]));
        }
        return result;
    }

    int findFirstBig(vector<pair<int, int>>& arr, int num) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid].first >= num) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (left == arr.size()) return -1;
        return arr[left].second;
    }
};