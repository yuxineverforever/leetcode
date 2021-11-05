/**
 *
 * Given a string s and a dictionary of strings wordDict, \
 * add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 *
 *
 *
 * DFS
 * 回溯+剪枝，利用一个map保留键值映射，想相当于加入剪枝操作，可以对之前计算过的避免重复计算，进而加速计算过程。
 *
 *
 */

#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {

public:
  static vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string,vector<string> > m;
    return helper(m,wordDict,s);
  }

  static vector<string> helper(unordered_map<string,vector<string> >& m,vector<string>& wordDict,string s){
    if(m.count(s)) return m[s];
    if(s.empty()) return {""};

    vector<string> res;

    for(auto word:wordDict){
      if(s.substr(0,word.size())!=word) continue;

      vector<string> tmp=helper(m,wordDict,s.substr(word.size()));

      for(auto itm:tmp){
        res.push_back(word+(itm.empty()?"":" "+itm));
      }

    }
    m[s]=res;
    return res;
  }

};

int main(){
  string s = "catsanddog";
  vector<string> wordDict{"cat","cats","and","sand","dog"};

  auto res = Solution::wordBreak(s,wordDict);
  for (auto& arr:res){
    std::cout << arr << std::endl;
  }

}

