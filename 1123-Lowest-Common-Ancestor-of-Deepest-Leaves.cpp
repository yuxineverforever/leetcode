/**
 * Q:
 *Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

    The node of a binary tree is a leaf if and only if it has no children
    The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
    The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.
 *
 *
 *
 *
 *
 * A:
 *
 *递归的实现

    递归条件：判断左右子树是否相等，相等则返回，意味着有两种情况
        叶子节点
        或者类似例子1里的 7,4的父节点2
    返回计算：就是取当前左右节点的最大深度+1
    优化：增加一个辅助map记录深度来快速获取
 *
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

class Solution {
private:
    int GetDepth(TreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return max(GetDepth(node->left), GetDepth(node->right)) + 1;
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == nullptr){
            return nullptr;
        }

        int l = GetDepth(root->left);
        int r = GetDepth(root->right);

        // 如果深度一样，那么就是可以返回子树
        if (l == r){
            return root;
        }
        // 对于深度不一样的情况，就走深度大的分支即可
        return (l > r) ? lcaDeepestLeaves(root->left) : lcaDeepestLeaves(root->right);
    }
};