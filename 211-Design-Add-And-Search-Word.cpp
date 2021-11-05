/**
 *
 * Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

    WordDictionary() Initializes the object.
    void addWord(word) Adds word to the data structure, it can be matched later.
    bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-add-and-search-words-data-structure
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 * Q: Implement a Trie
 * A: just like this.
 *
 *
 * Another question: How to implement the delete operation for Trie?
 *
 */
struct TrieNode{
    vector<TrieNode *> child;
    bool isEnd;
    TrieNode() {
        this->child = vector<TrieNode *>(26,nullptr);
        this->isEnd = false;
    }
};

void insert(TrieNode * root, const string & word) {
    TrieNode * node = root;
    for (auto c : word) {
        if (node->child[c - 'a'] == nullptr) {
            node->child[c - 'a'] = new TrieNode();
        }
        node = node->child[c - 'a'];
    }
    node->isEnd = true;
}

class WordDictionary {
public:
    WordDictionary() {
        trie = new TrieNode();
    }

    void addWord(string word) {
        insert(trie,word);
    }

    bool search(string word) {
        return dfs(word, 0, trie);
    }

    bool dfs(const string & word,int index,TrieNode * node) {
        if (index == word.size()) {
            return node->isEnd;
        }
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z') {
            TrieNode * child = node->child[ch - 'a'];
            if (child != nullptr && dfs(word, index + 1, child)) {
                return true;
            }
        } else if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                TrieNode * child = node->child[i];
                if (child != nullptr && dfs(word, index + 1, child)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    TrieNode * trie;
};