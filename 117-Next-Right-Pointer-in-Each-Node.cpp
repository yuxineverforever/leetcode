#include <iostream>
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node():val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        Node* p1 = root;
        while(p1)
        {
            Node* dummy = new Node(-1);
            Node* ptr = dummy;
            while(p1)
            {
                if(p1->left)
                {
                    ptr->next = p1->left;
                    ptr = ptr->next;
                }
                if(p1->right)
                {
                    ptr->next = p1->right;
                    ptr = ptr->next;
                }
                p1 = p1->next;
            }
            p1 = dummy->next;
        }
        return root;
    }
};