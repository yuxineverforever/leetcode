/*
 * We can shift a string by shifting each of its letters to its successive letter.
 *  For example, "abc" can be shifted to be "bcd".
 *
 * We can keep shifting the string to form a sequence.
 *  For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" -> ... -> "xyz".
 *  Given an array of strings strings, group all strings[i] that belong to the same shifting sequence.
 *  You may return the answer in any order.


We can shift a string by shifting each of its letters to its successive letter.

For example, "abc" can be shifted to be "bcd".

We can keep shifting the string to form a sequence.

For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" -> ... -> "xyz".

Given an array of strings strings, group all strings[i] that belong to the same shifting sequence. You may return the answer in any order.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-shifted-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/**
 **  turn every string into the string begin with 'a';
 **/

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<std::vector<std::string> > groupStrings(std::vector<std::string>& strings) {
        std::vector<std::vector<std::string> > res;
        std::unordered_map<std::string, std::vector<std::string> > hashmap;
        for(std::string s : strings){
            std::string ss(s);
            for(int i = 0; i < ss.size(); i++) {
                ss[i] = (ss[i] - s[0] + 26) % 26 +'a';
            }
            hashmap[ss].push_back(s);
        }
        for(auto i : hashmap) {
            res.push_back(i.second);
        }
        return res;
    }
};

int main(){
    Solution s;
    std::vector<std::string> strings;
    strings.push_back("abc");
    strings.push_back("bcd");
    strings.push_back("acef");
    strings.push_back("xyz");
    strings.push_back("az");
    strings.push_back("ba");
    strings.push_back("a");
    strings.push_back("z");
    auto returnVal = s.groupStrings(strings);
    return 0;
}