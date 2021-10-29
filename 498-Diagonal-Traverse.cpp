/*
 * traverse the matrix in the diagonal.
 *
 *
 *
 */
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // 真有你的
        /*
            找规律:

            注意左下(+1, -1)和右上移动(-1, +1)不会改变当前(行 + 列)的和, 即判断方式为行 + 列的和
            if (行 + 列)是偶数, 就是右上, 是奇数就是左下

            左下 = [1, -1]
            如果在最后一行 => 向右 [0, 1]  (先判断行, 防止在左下角的时候向下则越界)
            如果在第一列 => 向下 [1, 0]

            右上 = [-1, 1]
            如果在最后一列 => 向下 [1, 0]   (先判断列, 防止在右上角时候向右则越界)
            如果在第一行 => 向右 [0, 1]
        */
        vector<int> ans;
        int row = mat.size(), col = mat[0].size();
        int all = row * col; // 元素个数
        int x = 0, y = 0;
        for (int i = 0; i < all; ++i) {
            ans.push_back(mat[x][y]);
            // 右上
            if ((x + y) % 2 == 0) {
                if (y == col - 1) ++x; // 最后一列
                else if (x == 0) ++y; // 第一行
                else --x, ++y; // 正常右上
            } else {
                if (x == row - 1) ++y;
                else if (y == 0) ++x;
                else ++x, --y;
            }
        }
        return ans;
    }
};