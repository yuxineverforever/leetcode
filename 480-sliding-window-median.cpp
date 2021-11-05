/*
 *
 * The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.

    For examples, if arr = [2,3,4], the median is 3.
    For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.

You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-window-median
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
// https://leetcode-cn.com/problems/sliding-window-median/

class Solution {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int> > big;
    unordered_map<int, int> mp;
    double get(int& k){
        if(k%2) return small.top();
        else return ((long long)small.top()+big.top())*0.5;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        for(int i = 0; i < k; i++){
            small.push(nums[i]);
        };

        for(int i = 0; i < k / 2; i++){
            big.push(small.top());
            small.pop();
        }

        vector<double> ans{get(k)};
        for(int i = k; i < nums.size(); i++){

            int balance = 0;
            int l = nums[i-k];
            mp[l]++;

            if(!small.empty() && l<=small.top()){
                balance--;
            }
            else {
                balance++;
            }

            if(!small.empty() && nums[i] <= small.top()){
                small.push(nums[i]);
                balance++;
            } else{
                big.push(nums[i]);
                balance--;
            }
            if(balance>0){
                big.push(small.top());
                small.pop();
            }
            if(balance<0){
                small.push(big.top());
                big.pop();
            }
            while(!small.empty() && mp[small.top()]>0){
                mp[small.top()]--;
                small.pop();
            }
            while(!big.empty() && mp[big.top()]>0){
                mp[big.top()]--;
                big.pop();
            }
            ans.push_back(get(k));
        }
        return ans;
    }
};