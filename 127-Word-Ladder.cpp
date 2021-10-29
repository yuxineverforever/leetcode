/**
 * Q: Get the shortest transformation path from begin word to end word.
 * Using the words in dictionary. Return the path length.
 *
 * A: double BFS here.
 *
 * BeginSet: contain the begin set of words.
 * EndSet: contain the end set of words.
 * TempSet: contain the one step lookup words.
 *
 */

#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;
class Solution {
public:
    static int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> wordDict(wordList.begin(), wordList.end());

        if (wordDict.find(endWord) == wordDict.end()){
            return 0;//Not FOUND 404
        }

        unordered_set<string> beginSet{beginWord};

        unordered_set<string> endSet{endWord};

        int step = 1;

        for (; !beginSet.empty();){

            unordered_set<string> tempSet;

            ++step;

            for (auto s : beginSet) {
                wordDict.erase(s);
            }

            for (auto s : beginSet) {

                for (int i = 0; i < s.size(); ++i){

                    string str = s;

                    for (char c = 'a'; c <= 'z'; ++c){

                        str[i] = c;

                        if (wordDict.find(str) == wordDict.end()){
                            continue;
                        }

                        if (endSet.find(str) != endSet.end()){
                            return step;
                        }

                        tempSet.insert(str);
                    }
                }
            }
            // which direction is faster, Begin to end or end to begin.
            if (tempSet.size() < endSet.size()){
                beginSet = tempSet;
            } else {
                beginSet = endSet;
                endSet = tempSet;
            }

        }
        return 0;
    }

};

int main(){
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList{"hot","dot","dog","lot","log","cog"};
  std::cout << Solution::ladderLength(beginWord,endWord,wordList) << std::endl;

  return 0;
}