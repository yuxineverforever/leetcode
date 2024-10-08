/**
 * You are given several boxes with different colors represented by different positive numbers.

You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.

Return the maximum points you can get.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-boxes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 *
 */
class Solution {
public:
    int dp(vector<vector<vector<int>>>& memo, vector<int>& right, vector<int>& boxes, int presame, int i, int r) {

        if (i > r) return presame * presame;
        if (memo[presame][i][r] != -1) return memo[presame][i][r];
        int res = presame * presame;
        int j = i;
        while (right[j] == j+1 && j+1 <= r) j++;
        res = max(res, (presame + j-i+1) * (presame + j-i+1) + dp(memo, right, boxes, 0, j+1, r));
        int nextj = right[j];
        while (nextj <= r) {
            res = max(res, dp(memo, right, boxes, 0, j+1, nextj-1) + dp(memo, right, boxes, presame+j-i+1, nextj, r));
            nextj = right[nextj];
        }
        return memo[presame][i][r] = res;
    }
    int removeBoxes(vector<int>& boxes) {
        unordered_map<int, int> r;
        int n = boxes.size();
        vector<int> right(n, n);
        for (int i = boxes.size() - 1; i >= 0; i--) {
            if (r.find(boxes[i]) != r.end()) right[i] = r[boxes[i]];
            r[boxes[i]] = i;
        }
        vector<vector<vector<int>>> memo(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        return dp(memo, right, boxes, 0, 0, n-1);
    }
};