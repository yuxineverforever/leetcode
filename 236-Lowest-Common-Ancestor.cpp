/**
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 *
 */
#include <iostream>
#include <vector>

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == nullptr || root == p || root == q) return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);

        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if(left == nullptr && right == nullptr) return nullptr; // 1.

        if(left == nullptr) return right; // 3.

        if(right == nullptr) return left; // 4.

        return root; // 2. if(left != null and right != null)
    }
};