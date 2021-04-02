#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        stack<int> symbol;
        symbol.push(1);
        int res = 0;
        int punctuation = 1;
        for(int i = 0; i < s.length(); i ++) {
            if (s[i] == ' '){
                continue;
            } else if (s[i] == '+') {
                punctuation = symbol.top();
            } else if (s[i] == '-') {
                punctuation = -symbol.top();
            } else if (s[i] == '(') {
                symbol.push(punctuation);
            } else if (s[i] == ')') {
                symbol.pop();
            } else {
                long num = 0;
                while(i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i ++;
                }
                i --;
                res += punctuation * num;
            }
        }
        return res;
    }
};


int main(){

    Solution s;
    std::cout << "res: " << s.calculate("1 - (100 - (99 + 1))") << std::endl;
    return 0;
}