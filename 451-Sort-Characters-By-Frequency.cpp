/**
 * Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-characters-by-frequency
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
class Solution {
public:
    std::string frequencySort(std::string s) {
      std::unordered_map<char,int>map;

        for(char i : s)
            map[i]++;

        s="";
        std::vector<std::pair<int,char> > p;

        for(auto i:map)
            p.emplace_back(i.second,i.first);

        sort(p.rbegin(),p.rend());

        for(auto & i : p)
            s+=std::string(i.first,i.second);

        return s;
    }
};


int main(){

    Solution s;
    std::cout << s.frequencySort("ehea");

    return 0;
}