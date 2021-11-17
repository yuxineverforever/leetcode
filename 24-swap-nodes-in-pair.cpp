/***
 * Q:
 *
 * Given a linked list,
 * swap every two adjacent nodes and return its head.
 * You must solve the problem without modifying the values in the list's nodes
 * (i.e., only nodes themselves may be changed.)
 *
 *  input: 1->2->3->4
 *  output: 2->1->4->3
 *
 * A:
 * use recursion.
 *
 */
struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(head==NULL || head->next==NULL)
            return head;
        struct ListNode* next=head->next;
        struct ListNode* temp=next->next;
        next->next=head;
        head->next=swapPairs(temp);
        return next;

    }
};
