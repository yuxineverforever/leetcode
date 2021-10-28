#include <iostream>
#include <cmath>
#include <memory>

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