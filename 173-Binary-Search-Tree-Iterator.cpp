/**
 * Q: Implement a BSTIterator that can do in-order traverse.
 *
 *
 * A: 栈存放 结点和一个布尔值（标记，表示此结点的左子树是否已经访问过）. 栈里面存放的始终是整棵树的未被处理的最左路径上的结点
 *
 * 从栈中取出结点，如果它有左子树，那么将它和它的左子树入栈（左子树在栈顶），然后递归处理，这样最终栈里面存放的就是整棵树的最左路径

使用一个布尔值标记结点的左子树是否已经被访问，如果访问了，那么就访问它自身，并将右子树（如果有）入栈，这样就形成了 dfs

 *
 */
class BSTIterator {
    stack<pair<TreeNode*, bool>> stk;
public:
    BSTIterator(TreeNode* root) {
        if (root)
            stk.push({root, 0});
    }

    int next() {
        if (!hasNext()) return 0;
        auto cur = stk.top();
        stk.pop();
        /* 0: 左子树未处理，自身再次入栈，并标记为 1，然后左子树入栈，递归处理左子树 */
        if (cur.second == 0) {
            stk.push({cur.first, 1});
            if (cur.first->left)
                stk.push({cur.first->left, 0});
            return next();
        } else {
            /* 1: 左子树已处理，右子树入栈，然后返回自身 */
            if (cur.first->right)
                stk.push({cur.first->right, 0});
            return cur.first->val;
        }
    }

    bool hasNext() {
        return !stk.empty();
    }
};