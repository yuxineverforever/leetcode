/**
 * copy a linked list with random pointer
 *
 *
 */

//第一步，根据遍历到的原节点创建对应的新节点，每个新创建的节点是在原节点后面，比如下图中原节点1不再指向原原节点2，而是指向新节点1
//第二步, 是最关键的一步，用来设置新链表的随机指针
//第三步, 简单了，只要将两个链表分离开，再返回新链表就可以了

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if ( !head ) {
            return nullptr;
        }
        Node *cur = head;
        // 1. 在原节点的每个节点后创建一个节点
        while ( cur ) {
            Node *newNode = new Node(cur -> val);
            newNode -> next = cur -> next;
            cur -> next = newNode;
            cur = cur -> next ->next;
        }

        // 2. 更新新节点的random指针
        cur = head;
        while ( cur ) {
            if ( cur -> random == nullptr ) {
                cur -> next -> random = nullptr;
            } else {
                cur -> next -> random = cur -> random -> next;
            }
            cur = cur -> next -> next;
        }

        // 3. 将两个链表拆开
        Node *dummy = new Node(-1);
        Node *curnew = dummy, *curold = head;
        while ( curold ) {
            Node *next = curold -> next -> next;
            curnew -> next = curold -> next;
            curold -> next = next;
            curnew = curnew -> next;
            curold = curold -> next;
        }
        return dummy -> next;
    }
};