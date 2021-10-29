/**
 * Q: flatten an BST into list. The order should be the same as pre-order traverse.
 * A: move　the right subtree to follow the most right node under the left subtree.
 *
 * space : O(1)
 */
class Solution {
public:
  void flatten(TreeNode* root) {
    TreeNode *curr = root;
    while (curr != nullptr) {
      if (curr->left != nullptr) {
        auto next = curr->left;
        auto predecessor = next;
        while (predecessor->right != nullptr) {
          predecessor = predecessor->right;
        }
        predecessor->right = curr->right;
        curr->left = nullptr;
        curr->right = next;
      }
      curr = curr->right;
    }
  }
};
/**
 *  common preorder traverse.
 *  space: O(n)
 */

class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> l;
        preorderTraversal(root, l);
        int n = l.size();
        for (int i = 1; i < n; i++) {
            TreeNode *prev = l.at(i - 1);
            *curr = l.at(i);
            prev->left = nullptr;
            prev->right = curr;
        }
    }

    void preorderTraversal(TreeNode* root, vector<TreeNode*> &l) {
        if (root != NULL) {
            l.push_back(root);
            preorderTraversal(root->left, l);
            preorderTraversal(root->right, l);
        }
    }
};