/**


Q: Given an integer array nums sorted in non-decreasing order,
 return an array of the squares of each number sorted in non-decreasing order.


数组其实是有序的， 只不过负数平方之后可能成为最大数了。

那么数组平方的最大值就在数组的两端，不是最左边就是最右边，不可能是中间。

此时可以考虑双指针法了，i指向起始位置，j指向终止位置。

定义一个新数组result，和A数组一样的大小，让k指向result数组终止位置。


 如果A[i] * A[i] < A[j] * A[j] 那么result[k--] = A[j] * A[j]; 。

如果A[i] * A[i] >= A[j] * A[j] 那么result[k--] = A[i] * A[i]; 。


 A: two pointer method since the extreme value appears on either the left end or the right end.

 **/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);
        for (int i = 0, j = A.size() - 1; i <= j;) { // 注意这里要i <= j，因为最后要处理两个元素
            if (A[i] * A[i] < A[j] * A[j])  {
                result[k--] = A[j] * A[j];
                j--;
            }
            else {
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }
};