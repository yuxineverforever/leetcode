/**
Q: Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

A: BFS

**/
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;

        queue<TreeNode*> mq;
        mq.push(root);

        while(mq.size() > 0){
            int n = mq.size();
            int max = INT_MIN;
            for(int i = 0; i < n; i++){
                root = mq.front();
                mq.pop();
                if(root->val > max)
                    max = root->val;

                if(root->left != NULL)
                    mq.push(root->left);
                if(root->right != NULL)
                    mq.push(root->right);
            }
            ans.push_back(max);
        }
        return ans;
    }
};