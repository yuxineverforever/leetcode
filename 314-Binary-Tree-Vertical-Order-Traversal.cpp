/**
 *
 * Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).
 * If two nodes are in the same row and column, the order should be from left to right.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-vertical-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 *  Input: root = [3,9,20,null,null,15,7]
 *  Output: [[9],[3,15],[20],[7]]
 *
 *
 *  Input: root = [3,9,8,4,0,1,7]
 *  Output: [[4],[9],[3,0,1],[8],[7]]
 *
 *
 *  Input: root = [3,9,8,4,0,1,7,null,null,null,2,5]
 *  Output: [[4],[9,5],[3,0,1],[8,2],[7]]
 */


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

#include <iostream>
#include <queue>
#include <vector>
#include <map>
class Solution {
public:
    std::vector<std::vector<int>> verticalOrder(TreeNode* root) {

        std::map<int, std::vector<int> > m;

        using T = std::pair<TreeNode*,int>;

        using P = std::pair<int,int>;

        std::priority_queue<P,std::vector<P>, std::greater<P>> pq;

        std::queue<T> q;

        std::vector<std::vector<int>> res;

        if(!root) return res;

        q.push(T(root, 0));

        m[0].push_back(root->val);


        while(!q.empty()){

            int sz = q.size();

            while(sz--){

                T curr = q.front();

                q.pop();

                if(curr.first->left){
                    q.push(T(curr.first->left,curr.second-1));
                    m[curr.second-1].push_back(curr.first->left->val);
                }

                if(curr.first->right){
                    q.push(T(curr.first->right,curr.second+1));
                    m[curr.second+1].push_back(curr.first->right->val);
                }
            }
        }

        for(auto& p: m){
            res.push_back(p.second);
        }

        return res;
    }
};