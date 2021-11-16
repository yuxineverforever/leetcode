/**
 * Q:
 * In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.
 *
 *  Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.
 *
 * A:
 * First, construct an array storing the order of the dictionary.
 * Then compare consecutive word directly.
 *
 */
class Solution {
private:
    int char2order[26];

    bool IsLexi(const string& a, const string& b)
    {
        int n = min(a.size(), b.size());
        for (int i = 0; i < n; ++i)
        {
            int ia = char2order[a[i]-'a'];
            int ib = char2order[b[i]-'a'];
            if (ia < ib)
            {
                return true;
            }
            else if (ia > ib)
            {
                return false;
            }
        }

        // 说明a长度不大于b,则为true
        return n == a.size();
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
        memset(char2order, 0, sizeof(char2order));
        for (int i = 0; i < order.size(); ++i)
        {
            char2order[order[i]-'a'] = i;
        }

        // 遍历去比较是否满足
        for (int i = 0; i < words.size()-1; ++i)
        {
            if (!IsLexi(words[i], words[i+1]))
            {
                return false;
            }
        }

        return true;
    }
};