/**
 * Definition for a binary tree node.
 *
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 *
 * Q: Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

 *
 *
 * A: BFS.
 *
 */

class Solution {
public:

    bool isCompleteTree(TreeNode* root) {
        // 层序遍历的辅助利器
        queue<TreeNode*> q;
        // 记录是否已经遍历到null结果
        bool reachNull = false;
        q.push(root);
        while (!q.empty()){

            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr){
                // 发现空结点了
                reachNull = true;
                continue;
            } else {
                // 发现null结点后出现非空结点，发现不完全了
                if (reachNull){
                    return false;
                }
                // 继续遍历左右节点
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return true;
    }
};