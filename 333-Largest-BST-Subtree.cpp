/**
 *
 * Given the root of a binary tree, find the largest subtree, which is also a Binary Search Tree (BST), where the largest means subtree has the largest number of nodes.

A Binary Search Tree (BST) is a tree in which all the nodes follow the below-mentioned properties:

    The left subtree values are less than the value of their parent (root) node's value.
    The right subtree values are greater than the value of their parent (root) node's value.

Note: A subtree must include all of its descendants.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-bst-subtree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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