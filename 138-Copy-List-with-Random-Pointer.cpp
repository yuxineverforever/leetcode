/**
 * A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

    val: an integer representing Node.val
    random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.

Your code will only be given the head of the original linked list.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/copy-list-with-random-pointer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 *
 * A:
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