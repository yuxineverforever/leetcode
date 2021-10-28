/**
 * Q:
 *
 * Given the root of a binary tree,
 * imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 *
 * A: BFS is enough.
 * Easy. Almost the same as Binary Tree Vertical Order.
 *
 *
 *
 **/

#include <algorithm>
#include <iostream>
#include <map>
#include <opencl-c.h>
#include <queue>
#include <unordered_map>
#include <vector>

struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  std::vector<int> rightSideView(TreeNode* root) {

    std::unordered_map<int, int> rightmostValueAtDepth;
    int max_depth = -1;

    std::queue<TreeNode*> nodeQueue;
    std::queue<int> depthQueue;
    nodeQueue.push(root);
    depthQueue.push(0);

    while (!nodeQueue.empty()) {
      TreeNode* node = nodeQueue.front();
      nodeQueue.pop();
      int depth = depthQueue.front();
      depthQueue.pop();

      if (node != NULL) {

        // 维护二叉树的最大深度
        max_depth = max(max_depth, depth);

        // 由于每一层最后一个访问到的节点才是我们要的答案，因此不断更新对应深度的信息即可
        rightmostValueAtDepth[depth] =  node -> val;

        nodeQueue.push(node -> left);
        nodeQueue.push(node -> right);
        depthQueue.push(depth + 1);
        depthQueue.push(depth + 1);
      }
    }

    std::vector<int> rightView;
    for (int depth = 0; depth <= max_depth; ++depth) {
      rightView.push_back(rightmostValueAtDepth[depth]);
    }

    return rightView;
  }
};