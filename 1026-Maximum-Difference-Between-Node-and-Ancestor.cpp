/**
 *
 * Q:
 * Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

 *
 *
 *
 *
 *
 * A:
 *
    先序遍历：根节点，左右节点
    把父节点的最大值和最小值传递下去，不断更新，同时计算最大差值
    不断更新的最大差值就是结果

 *
 *
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
    int res = 0;

    void dfs(TreeNode* root, int smallest, int largest){

        // 忽略为空的结点

        if (root != nullptr){

            res = max(res, max(abs(smallest-root->val), abs(largest-root->val)));

            // 更新最大值和最小值
            smallest = min(root->val, smallest);
            largest = max(root->val, largest);

            // 递归调用下一级
            dfs(root->left, smallest, largest);
            dfs(root->right, smallest, largest);

        }
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return res;
    }
};