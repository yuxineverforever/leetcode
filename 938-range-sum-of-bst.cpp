/**
 *
 * Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-of-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
class Solution {
public:
    int rangeSumBST(TreeNode *root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

class Solution {
public:
    int rangeSumBST(TreeNode *root, int low, int high) {
        int sum = 0;
        queue<TreeNode*> q({root});
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node == nullptr) {
                continue;
            }
            if (node->val > high) {
                q.push(node->left);
            } else if (node->val < low) {
                q.push(node->right);
            } else {
                sum += node->val;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return sum;
    }
};
