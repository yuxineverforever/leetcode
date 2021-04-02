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