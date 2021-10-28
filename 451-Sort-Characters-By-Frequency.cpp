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