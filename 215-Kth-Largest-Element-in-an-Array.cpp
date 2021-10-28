class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int le=0, ri=n-1;
        while(true){
            //快排框架
            int i=le, j=ri;
            int idx = rand() % (ri - le +1) + le;//随机选择pivot
            swap(nums[le], nums[idx]);
            while(i<j){
                while(i<j&&nums[j]>=nums[le]) --j;
                while(i<j&&nums[i]<=nums[le]) ++i;
                swap(nums[i], nums[j]);
            }
            swap(nums[i], nums[le]);//nums[le]应处的位置在索引i处

            if(i==n-k) return nums[i];//若恰为倒数第K的位置
            else if(i>n-k) ri=i-1;//将查找范围放在该位置左侧
            else le=i+1;//将查找范围放在该位置右侧
        }
    }
};