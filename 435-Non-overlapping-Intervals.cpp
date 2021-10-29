/**
Given an array of intervals intervals where intervals[i] = [start_i, end_i],
return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

** Example 1: **

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

** Example 2: **

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

** Example 3: **

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
**/
/**
 * 题目的要求等价于「选出最多数量的区间，使得它们互不重叠」。由于选出的区间互不重叠，因此我们可以将它们按照端点从小到大的顺序进行排序，并且无论我们按照左端点还是右端点进行排序，得到的结果都是唯一的。
 * 这样一来，我们可以先将所有的 nnn 个区间按照左端点（或者右端点）从小到大进行排序，随后使用动态规划的方法求出区间数量的最大值。设排完序后这 nnn 个区间的左右端点分别为 l0,⋯ ,ln−1l_0, \cdots, l_{n-1}l0​,⋯,ln−1​ 以及 r0,⋯ ,rn−1r_0, \cdots, r_{n-1}r0​,⋯,rn−1​，那么我们令 fif_ifi​ 表示「以区间 iii 为最后一个区间，可以选出的区间数量的最大值」，状态转移方程即为：

fi=max⁡j<i ∧ rj≤li{fj}+1f_i = \max_{j < i ~\wedge~ r_j \leq l_i} \{ f_j \} + 1 fi​=j<i ∧ rj​≤li​max​{fj​}+1

即我们枚举倒数第二个区间的编号 jjj，满足 j<ij < ij<i，并且第 jjj 个区间必须要与第 iii 个区间不重叠。由于我们已经按照左端点进行升序排序了，因此只要第 jjj 个区间的右端点 rjr_jrj​ 没有越过第 iii 个区间的左端点 lil_ili​，即 rj≤lir_j \leq l_irj​≤li​，那么第 jjj 个区间就与第 iii 个区间不重叠。我们在所有满足要求的 jjj 中，选择 fjf_jfj​ 最大的那一个进行状态转移，如果找不到满足要求的区间，那么状态转移方程中 min⁡\minmin 这一项就为 000，fif_ifi​ 就为 111。

最终的答案即为所有 fif_ifi​ 中的最大值。
 *
 *
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        if (intervals.empty()) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
            return u[0] < v[0];
        });

        int n = intervals.size();

        vector<int> f(n, 1);

        // dynamic programming

        // f[i] = m                a                    x (f[j]+1)
        //        (i<j && interval[j][1] < interval[i][0])

        for (int i = 1;i < n; i++){
            for (int j = 0; j<i;j++){
                if (intervals[j][1] < intervals[i][0]){
                    f[i] = max(f[i],f[j]+1);
                }
            }
        }

        return n - *max_element(f.begin(), f.end());
    }
};