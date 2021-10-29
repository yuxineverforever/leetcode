/**
 * Q: look at a string from a 180 degree rotation.
 *
 * A: 当数字中有2，3，4，5，7的时候，直接返回false;
之后从字符串num结尾开始遍历，遇到的数字都倒过来;
如果最后返回str是否等于num;
 */
class Solution {
public:
    bool isStrobogrammatic(string num) {
        char shuzu[]={'2','3','4','5','7'};
        for(int i=0;i<num.size();i++){
            for(auto &x:shuzu){
                if(num[i]==x) return false;
            }
        }
        string str="";
        for(int i=num.size()-1;i>=0;i--){
            if(num[i]=='1') str+='1';
            else if(num[i]=='6') str+='9';
            else if(num[i]=='8') str+='8';
            else if(num[i]=='9') str+='6';
            else if(num[i]=='0') str+='0';
        }
        return str==num;
    }
};