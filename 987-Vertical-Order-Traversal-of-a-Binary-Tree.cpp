/**
 *
 *  Q: vertical order traverse of BST
 *
 *
 *  A: BFS.
 */
class Solution {
public:
    struct Node {
        int x, y;
        TreeNode *root;
        Node() {}
        Node(int a, int b, TreeNode *c) : x(a), y(b), root(c) {}
    };

    vector <vector <int>> ans;
    map <int, vector<int>> ss;

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return ans;
        queue <Node> q;
        q.push({0, 0, root});
        while(!q.empty()) {
            int n = q.size();
            map <int, vector<int>> tmp;         // 临时的 map
            for(int i = 0; i < n; i++) {
                auto k = q.front();
                q.pop();
                tmp[k.y].push_back(k.root->val);
                if(k.root->left) q.push({k.x + 1, k.y - 1, k.root->left});
                if(k.root->right) q.push({k.x + 1, k.y + 1, k.root->right});
            }
            for(auto &[x, y] : tmp) {           // 遍历
                sort(y.begin(), y.end());       // 排序
                for(auto &c : y) ss[x].push_back(c);         // 将节点加入第一个 map(ss) 中
            }
            tmp.clear();
        }
        for(auto &[x, y] : ss) {
            ans.push_back(y);
        }
        return ans;
    }
};