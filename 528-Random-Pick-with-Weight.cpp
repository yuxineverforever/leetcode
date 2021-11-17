/**
 * similar to 398 Equally Random Pick Index of Target
 *
 * Q: given an array w, pick the index from 0 to length(w)-1 using pickIndex().
 * w[i] indicates the probability of i being picked.
 *
 *
 * A: using presum + binary search.
 *
 * 设数组 w 的权重之和为 total。  据题目的要求，我们可以看成将 [1,total] 范围内的所有整数分成 n 个部分（其中 n 是数组 w 的长度），
 * 第 i 个部分恰好包含 w[i] 个整数，并且这 n 个部分两两的交集为空。随后我们在 [1,total]范围内随机选择一个整数 x，
 * 如果整数 x 被包含在第 i 个部分内，我们就返回 i。
 **/

class Solution {
public:
    vector<int> a;
    int sum = 0;
    Solution(vector<int>& w) {
        int n = w.size();
        for(int i = 0;i<n;i++){
            sum+=w[i];
            a.push_back(sum-1);
        }
    }

    int pickIndex() {
        int t = rand() % sum;
        return lower_bound(a.begin(),a.end(),t)-a.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */