#include <vector>
#include <iostream>
using namespace std;

/**
 *
 * Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diagonal-traverse
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 * Q: Traverse an m*n matrix in the diagonal order and print all the elements out.
 *
 * A:
 *
 **/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        /*
            找规律:

            注意左下 (+1, -1) 和右上移动 (-1, +1) 不会改变当前 (行 + 列) 的和, 即判断方式为 (行 + 列) 的和
            if (行 + 列)
                是偶数, 就是右上,
                是奇数就是左下

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
            // (x + y) % 2 is used to decide which diagonal line it is now in.
            if ((x + y) % 2 == 0) {
                if (y == col - 1) ++x; // deal with boundary
                else if (x == 0) ++y; // deal with boundary
                else --x, ++y; // right up
            } else {
                if (x == row - 1) ++y; // deal with boundary
                else if (y == 0) ++x; // deal with boundary
                else ++x, --y; // left down
            }
        }
        return ans;
    }
};

int main(){
    std::vector < std::vector<int> > m;
    std::vector<int> a1{1,2,3};
    std::vector<int> a2{4,5,6};
    std::vector<int> a3{7,8,9};
    m.push_back(a1);
    m.push_back(a2);
    m.push_back(a3);
    Solution s;
    auto res = s.findDiagonalOrder(m);
    for (auto & t : res){

      std::cout << t << std::endl;
    }
    return 0;

}

