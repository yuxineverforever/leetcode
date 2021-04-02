class Solution {
public:
    bool less(string& a, string& b, string& order) {
        int len = min(a.size(), b.size());
        for (int i = 0; i < len; i++) {
            if (order.find(a[i]) < order.find(b[i])) return true;
            else if (order.find(a[i]) > order.find(b[i])) return false;
        }
        if (len == a.size()) return true;
        else return false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < words.size() - 1; i++) {
            if (!less(words[i], words[i + 1], order)) return false;
        }
        return true;
    }
};