/**
Q:
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

    For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.

Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

A: A simple DFS can solve everything.

**/

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return DFS(root, 0);
    }

    int DFS(TreeNode* node, int tmp) {

        if (node == nullptr) {
            return 0;
        }

        int sum = tmp * 10 + node -> val;

        if (node -> left == nullptr && node -> right == nullptr) {
            return sum;
        }

        return DFS(node -> left, sum) + DFS(node -> right, sum);
    }
};
