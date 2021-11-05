/**
 * Q: A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 *
 *  A: dfs
 *
 */
#include <iostream>
#include <cmath>
#include <memory>
#include <c++/7/limits>

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPath = std::numeric_limits<int>::min();
    int dfs(TreeNode* root){
        if (root== nullptr){
            return 0;
        }
        // not all negative: use 0 for comparison here
        // all negative: replace 0 with std::numeric_limits<int>::min()
        int leftPath = std::max(0,dfs(root->left));
        int rightPath = std::max(0,dfs(root->right));
        maxPath = std::max(maxPath, leftPath+rightPath+root->val);
        return std::max(leftPath, rightPath) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
      return maxPath;
    }
};


int main(){
  int leftVal = -10;
  int rightVal = -30;
  int rootVal = -20;
  TreeNode* left = new TreeNode(leftVal);
  TreeNode* right = new TreeNode(rightVal);
  TreeNode* root = new TreeNode(rootVal,left,right);
  Solution s;
  std::cout << "max path: " << s.dfs(root) << std::endl;
  return 0;
}