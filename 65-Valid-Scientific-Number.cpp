#include <iostream>
#include <string>
/**
 * Q:
 * A valid number can be split up into these components (in order):
    - A decimal number or an integer.
    - (Optional) An 'e' or 'E', followed by an integer.
 *
 * A: simulating
 *
 * https://leetcode-cn.com/problems/valid-number/
 *
 */
/*
   A valid number can be split up into these components (in order):
    - A [[ decimal number ]] or an integer.
    - (Optional) An 'e' or 'E', followed by an integer.

   A decimal number can be split up into these components (in order):
    - (Optional) A sign character (either '+' or '-').
    - One of the following formats:
          - One or more digits, followed by a dot '.'.
          - One or more digits, followed by a dot '.', followed by one or more digits.
          - A dot '.', followed by one or more digits.

    An integer can be split up into these components (in order):
        - (Optional) A sign character (either '+' or '-').
        One or more digits.

    Given a string s, return true if s is a valid number.


 * For example, all the following are valid numbers:
 * ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]
 *
 *
 * while the following are not valid numbers:
 * ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]
 *
 *
 */

class Solution {
public:
  bool isNumber(std::string s) {

    int i=0;
    isSign(s, i);

    if(!isDecimal(s, i)){
      return false;
    }
    if(isExpo(s, i)){

      isSign(s, i);

      if(!isNum(s, i)){
        return false;
      }
    }
    if(i == s.size())
      return true;
    else
      return false;
  }

  bool isExpo(std::string s, int &i){
    if(s[i]=='e' || s[i]=='E')
    {
      i++;
      return true;
    }
    return false;

  }

  void isSign(std::string s, int &i){
    if(s[i] == '-' || s[i] == '+')
      i++;
  }

  bool isNum(std::string s, int &i){
    bool isNumber = false;
    while(i<s.size() && isdigit(s[i])){
      i++;
      isNumber = true;
    }
    return isNumber;
  }

  bool isDecimal(std::string s, int &i){
    bool numBefore = isNum(s, i);
    if(s[i] == '.')
      i++;
    bool numAfter = isNum(s, i);

    return numBefore || numAfter;
  }


};


int main(){

    Solution s;

    std::cout << s.isNumber("99e2.5") << std::endl;

    return 0;
}