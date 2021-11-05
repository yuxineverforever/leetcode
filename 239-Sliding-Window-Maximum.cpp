/**
 * You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-window-maximum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * Q: slide windows max
 *
 * A: Monotonic Queue
 */
class Solution {
public:
    class MonotonicQueue {
    private:
        deque<int> data;
    public:
        //单调队列的 push 方法依然在队尾添加元素，但是要把前面比新元素小的元素都删掉：
        void push(int n) {
            while (!data.empty() && data.back() < n)
                data.pop_back();
            data.push_back(n);
        }

        int max() { return data.front(); }

        // 之所以要判断 data.front() == n，是因为我们想删除的队头元素 n 可能已经被「压扁」了，这时候就不用删除了：
        void pop(int n) {
            if (!data.empty() && data.front() == n)
                data.pop_front();
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue window;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i < k - 1) {
                window.push(nums[i]);
            } else {
                window.push(nums[i]);
                res.push_back(window.max());
                window.pop(nums[i - k + 1]);
            }
        }
        return res;
    }
};