/**
 *
 * Q:
 * Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.


 * A: recursion.
 *
 *
 * @param root
 * @param subRoot
 * @return
 */

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(root==NULL){
        return false;
    }
    if(isEqual(root,subRoot)){
        return true;
    }
    return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
}
bool isEqual(TreeNode* root,TreeNode* subRoot){
    if(root==NULL || subRoot==NULL){
        return (root==subRoot);
    }
    if(root->val!=subRoot->val){
        return false;
    }
    return isEqual(root->left,subRoot->left) && isEqual(root->right,subRoot->right);
}