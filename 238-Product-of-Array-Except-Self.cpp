/**
 *
 * 使用前缀乘积和后缀乘积进行两次遍历，避免除法；
 * 同时对位于第一位和最后一位的数字特殊处理即可。
 *
 *
 * */
class Solution {
public static int[] productExceptSelf(int[] nums) {
        int len = nums.length;
        int[] ans = new int[len];

        // 初始化
        int prefixProduct = nums[0], suffixProduct = nums[len - 1];
        ans[0] = 1;
        ans[len - 1] = 1;


        // 从正数第二个开始才有前缀乘
        for (int i = 1; i < len; i++) {
            ans[i] = prefixProduct; // 也可以使用Arrays.fill方法将ans全部存1然后用乘法
            prefixProduct *= nums[i];
        }

        // 从倒数第二个开始才有后缀乘
        for (int i = len - 2; i >= 0; i--) {
            ans[i] *= suffixProduct;
            suffixProduct *= nums[i];
        }

        return ans;
    }
}