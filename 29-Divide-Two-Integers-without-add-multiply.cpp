/***
 * Q:Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
 *
 *
 *
 * A:举个例子：11 除以 3 。
 首先11比3大，结果至少是1，
 然后我让3翻倍，就是6，
 发现11比3翻倍后还要大，那么结果就至少是2了，
 那我让这个6再翻倍，得12，11不比12大，
 差点让就让刚才的最小解2也翻倍得到4了。但是我知道最终结果肯定在2和4之间。
 也就是说2再加上某个数，这个数是多少呢？我让11减去刚才最后一次的结果6，剩下5，
 我们计算5是3的几倍，也就是除法，看，递归出现了。说得很乱，不严谨，大家看个大概，然后自己在纸上画一画，或者直接看我代码就好啦！
 *
 * 11/3 = 2+(11-2*3)/3 = 3
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1){
            if(dividend>INT_MIN) return -dividend;// 只要不是最小的那个整数，都是直接返回相反数就好啦
            return INT_MAX;// 是最小的那个，那就返回最大的整数啦
        }
        long a = dividend;
        long b = divisor;
        int sign = 1;
        if((a>0&&b<0) || (a<0&&b>0)){
            sign = -1;
        }
        a = a>0?a:-a;
        b = b>0?b:-b;
        long res = div(a,b);
        if(sign>0)return res>INT_MAX?INT_MAX:res;
        return -res;
    }

    int div(long a, long b){  // 似乎精髓和难点就在于下面这几句
        if(a<b) return 0;
        long count = 1;
        long tb = b; // 在后面的代码中不更新b
        while((tb+tb)<=a){
            count = count + count; // 最小解翻倍
            tb = tb+tb; // 当前测试的值也翻倍
        }
        return count + div(a-tb,b);
    }
};