/**
 * Q:
 *A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Design an algorithm to insert a new node to a complete binary tree keeping it complete after the insertion.

Implement the CBTInserter class:

    CBTInserter(TreeNode root) Initializes the data structure with the root of the complete binary tree.
    int insert(int v) Inserts a TreeNode into the tree with value Node.val == val so that the tree remains complete, and returns the value of the parent of the inserted TreeNode.
    TreeNode get_root() Returns the root node of the tree.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/complete-binary-tree-inserter
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 *
 * A:
 *
 *
 *
 */
class CBTInserter {

public:

    TreeNode* mRoot;
    queue<TreeNode*> que;
    TreeNode* cur;

    CBTInserter(TreeNode* root) {

        mRoot = root;
        que.push(root);

        while(que.empty()==false){

            TreeNode* node = que.front();

            que.pop();

            if(node->left) que.push(node->left);

            if(node->right) que.push(node->right);

            if(node->left == nullptr || node->right == nullptr){
                cur=node;
                break;
            }
        }
    }

    int insert(int val) {

        if(cur->left==nullptr){
            cur->left = new TreeNode(val);
            que.push(cur->left);
        } else if (cur->right == nullptr){
            cur->right = new TreeNode(val);
            que.push(cur->right);
        }
        int ans=cur->val;
        if(cur->right){
            cur=que.front();
            que.pop();
        }
        return ans;
    }

    TreeNode* get_root() {
        return mRoot;
    }
};