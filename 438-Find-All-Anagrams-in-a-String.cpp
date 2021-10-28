
/*
 * sliding window + array
 *
 *
 */
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res, hash(26, 0), hashZero(26, 0);  //hashZero是用来判空的
        if (s.length() < p.length()) return res;        //模式串不长度能大于要查找的字符串长度

        for (int i = 0; i < p.length(); ++i)            //构造哈希表
        {
            hash[p[i] - 'a'] ++ ;
            hash[s[i] - 'a'] -- ;
        }

        if (hash == hashZero) res.push_back(0);

        for (int i = p.length(); i < s.length(); ++ i)  //注意循环从s1.length()开始
        {
            hash[s[i] - 'a'] -- ;                       //滑动窗口右端推进
            hash[s[i - p.length()] - 'a'] ++ ;          //滑动窗口左端恢复
            if (hash == hashZero) res.push_back(i - p.length() + 1);
        }
        return res;
    }
};