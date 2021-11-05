/**
 *  Q:
 *  Given the head of a singly linked list where elements are sorted in ascending order, \
 *  convert it to a height balanced BST.
    For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 *
 *  A: recursion.
 *
 *
 **/
#include <iostream>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

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

    ListNode* getMedian(ListNode* left, ListNode* right){
        ListNode * slow = left;
        ListNode * fast = left;
        for (;fast->next!=right && fast!=right;fast=fast->next){
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        }
        return slow;
    }

    TreeNode* buildBST(ListNode* left, ListNode* right){
        if (left == right) return nullptr;
        ListNode* midNode = getMedian(left,right);
        TreeNode* root = new TreeNode(midNode->val);
        root->left = buildBST(left, midNode);
        root->right = buildBST(midNode->next, nullptr);
        return root;
    }

};