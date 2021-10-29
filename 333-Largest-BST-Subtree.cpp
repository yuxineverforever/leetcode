/**
 * Q: given a BST, find the largest BST subtree.
 *
 * A: DFS.
 *
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int largestBSTSubtree(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        if (isBST(root, INT_MIN, INT_MAX) == true)
            return cnt(root);
        return std::max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }

    bool isBST(TreeNode* root, int L, int R)            //判断是否为BST
    {
        if (root == NULL)
            return true;
        if (root->val <= L || R <= root->val)
            return false;
        return isBST(root->left, L, root->val) && isBST(root->right, root->val, R);
    }

    int cnt(TreeNode* root)                             //统计这个棵树，有多少结点
    {
        if (root == NULL)
            return 0;
        return cnt(root->left) + cnt(root->right) + 1;
    }
};