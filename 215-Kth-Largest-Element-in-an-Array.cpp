/**
 * Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 *我们可以用快速排序来解决这个问题，先对原数组排序，再返回倒数第 kkk 个位置，这样平均时间复杂度是 O(nlog⁡n)O(n \log n)O(nlogn)，但其实我们可以做的更快。

首先我们来回顾一下快速排序，这是一个典型的分治算法。我们对数组 a[l⋯r]a[l \cdots r]a[l⋯r] 做快速排序的过程是（参考《算法导论》）：

    分解： 将数组 a[l⋯r]a[l \cdots r]a[l⋯r] 「划分」成两个子数组 a[l⋯q−1]a[l \cdots q - 1]a[l⋯q−1]、a[q+1⋯r]a[q + 1 \cdots r]a[q+1⋯r]，使得 a[l⋯q−1]a[l \cdots q - 1]a[l⋯q−1] 中的每个元素小于等于 a[q]a[q]a[q]，且 a[q]a[q]a[q] 小于等于 a[q+1⋯r]a[q + 1 \cdots r]a[q+1⋯r] 中的每个元素。其中，计算下标 qqq 也是「划分」过程的一部分。
    解决： 通过递归调用快速排序，对子数组 a[l⋯q−1]a[l \cdots q - 1]a[l⋯q−1] 和 a[q+1⋯r]a[q + 1 \cdots r]a[q+1⋯r] 进行排序。
    合并： 因为子数组都是原址排序的，所以不需要进行合并操作，a[l⋯r]a[l \cdots r]a[l⋯r] 已经有序。
    上文中提到的 「划分」 过程是：从子数组 a[l⋯r]a[l \cdots r]a[l⋯r] 中选择任意一个元素 xxx 作为主元，调整子数组的元素使得左边的元素都小于等于它，右边的元素都大于等于它， xxx 的最终位置就是 qqq。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-leetcode-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 *
 */
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