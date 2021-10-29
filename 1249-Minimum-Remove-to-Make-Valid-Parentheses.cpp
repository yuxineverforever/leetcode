/**
 *
 * A stack is enough to make everything work.
 *
 */
#include <string>
#include <iostream>
#include <stack>
class Solution {
public:
  std::string minRemoveToMakeValid(std::string s) {

    std::stack<int> braket;

    int sLen = s.size();

    for(int i =0; i<sLen ; ++i){
      if(s[i] == '(' || s[i] == ')'){
        if(s[i] == '(') braket.push(i);
        else if(braket.empty()) {
          s.erase(i,1);
          --sLen;
          --i;
        }
        else braket.pop();
      }
    }

    while(!braket.empty()){
      int i = braket.top();
      s.erase(i,1);
      braket.pop();
    }

    return s;

  }
};