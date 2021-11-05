/**
 *
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-trie-prefix-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


 *
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 26;
class Trie {
public:
    bool is_str;
    // 标识当前结点是否为一个完整的字符串
    Trie *next[MAXN];
    // 下一个结点的指针数组
    Trie(){
        is_str = NULL;
        memset(next,0,sizeof(next));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *cur = this; // cur初始化为根结点指针
        for(char w : word){ // 遍历word中的每一个字符
            if(cur->next[w-'a']==NULL){ // 下一个结点不存在，新增一个结点
                Trie *new_node = new Trie();
                cur->next[w-'a'] = new_node;
            }
            cur = cur->next[w-'a'];
        }
        cur->is_str = true; // 当前结点已经是一个完整的字符串了
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *cur = this;
        for(char w : word){
            if(cur!=NULL)
                cur = cur->next[w-'a']; // 更新cur指针的指向，使其指向下一个结点
        }
        return (cur!=NULL&&cur->is_str); // cur指针不为空且cur指针指向的结点为一个完整的字符串，则成功找到字符串
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *cur = this;
        for(char w : prefix){
            if(cur!=NULL)
                cur = cur->next[w-'a'];
        }
        return (cur!=NULL); // 相比search(),这里只需判断cur指针是否为空就行了
    }
};

int main() {
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple");   // 返回 true
    cout << trie->search("app");     // 返回 false
    cout << trie->startsWith("app");
    trie->insert("app");
    cout << trie->search("app");     // 返回 true
    return 0;
}