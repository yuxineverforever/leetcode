/**
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

 *
 * A: IN-ORDER TRAVERSAL OF bst
 * https://leetcode-cn.com/problems/validate-binary-search-tree/solution/
 */
class Solution {
public:
    long pre = std::numeric_limits<long>::min();
    bool isValidBST(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        if (!isValidBST(root->left)){
            return false;
        }
        if (root->val <= pre){
            return false;
        }
        pre = root->val;
        return isValidBST(root->right);
    }
};