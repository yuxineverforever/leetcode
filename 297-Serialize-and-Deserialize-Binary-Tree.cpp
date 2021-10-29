/**
 *
 * Q: Serialize and de-serialize a BST
 * A: BFS.
 *
 */
class Codec {
public:
    // 序列化，返回的字符串最后都会多一个 ','
    string serialize(TreeNode* root) {
        // 如果是空，直接返回
        if (root == nullptr) {
            return "null,";
        }
        // BFS
        queue<TreeNode*> q;
        q.push(root);
        string res;
        while (!q.empty()) {
            // 每一层已有结点数
            int size = q.size();
            for (int i= 0; i < size; i++) {
                TreeNode* now = q.front();
                q.pop();
                // 如果为空，就直接+null然后continue
                if (now == nullptr) {
                    res += "null,";
                    continue;
                }
                // 不为空的话，队列中加入他的左右儿子
                res += to_string(now->val) + ",";
                q.push(now->left);
                q.push(now->right);
            }
        }
        // cout << res << endl;
        return res;
    }

    // 将序列化的字符串转成树节点数组
    vector<TreeNode*> toArray(string data) {
        vector<TreeNode*> nodes;
        // 分割点，也就是 ',' 所在下标+1
        int sep = 0;
        for (int i = 0; i < data.size(); i++) {
            // 当遇到 ','时，分割字符串
            if (data[i] == ',') {
                // str代表每一个结点的 ‘值’（可能是null）
                string str = data.substr(sep,i-sep);
                // 记录下一个分割点
                sep = i+1;
                // 创建一个新结点
                TreeNode* node = str == "null" ? nullptr : new TreeNode(stoi(str));
                // 收集所有结点
                nodes.emplace_back(node);
            }
        }
        // for (auto x : nodes) {
        //     cout << (x==nullptr? 0 : x->val) << " ";
        // }
        return nodes;
    }

    // 反序列化
    TreeNode* deserialize(string data) {
        // 将序列化字符串转成结点数组
        vector<TreeNode*> nodes = toArray(data);

        /*
          bfs思路：
            可以知道二叉树每一层最大结点数规律如下：
            * 第一层1个 第二层2个 第三层4个 第n层就是1<<(n-1)个
            *

            可以利用这一规律，来记录每一层的父节点。
            * 如果父节点是空，那他就不孕不育没有儿子；
            * 如果父节点不为空，那接下来两个结点就是他的左右儿子

        */
        // 用size表示当前层的结点数 
        int size = 1;
        int n = nodes.size();
        // pos来代表容器中对应的结点下标
        int pos = 1;
        while (pos < n) {
            // 每一层的开始下标是size/2，结束下标是size-1
            for (int i = size/2; i < size; i++) {
                // i没有越界 且 结点不为空 ， 那么他就可以有儿子
                if (i < n && nodes[i]) {
                    // 如果pos没有越界，就去当他的儿子（先左在右）
                    if (pos < n) {
                        nodes[i]->left = nodes[pos++];
                    }
                    if (pos < n) {
                        nodes[i]->right = nodes[pos++];
                    }
                }
            }
            // 即将到达下一层，结点数size增加
            size *= 2;
        }
        // 返回数组首个元素，也就是树的祖宗结点
        return nodes[0];
    }
};