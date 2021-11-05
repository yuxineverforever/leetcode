/**
 * A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings with their lengths. The lengths should not have leading zeros.

For example, a string such as "substitution" could be abbreviated as (but not limited to):

    "s10n" ("s ubstitutio n")
    "sub4u4" ("sub stit u tion")
    "12" ("substitution")
    "su3i1u2on" ("su bst i t u ti on")
    "substitution" (no substrings replaced)

The following are not valid abbreviations:

    "s55n" ("s ubsti tutio n", the replaced substrings are adjacent)
    "s010n" (has leading zeros)
    "s0ubstitution" (replaces an empty substring)

Given a string word and an abbreviation abbr, return whether the string matches the given abbreviation.

A substring is a contiguous non-empty sequence of characters within a string.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-word-abbreviation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
class Solution {
public:
    bool validWordAbbreviation(string w, string a) {
        int l=0,r=0,shuzi;
        bool tag=false;
        string str="";
        while(l<w.length()&&r<a.length()){
            //如果有两个字母不同，则直接返回false;
            if(w[l]!=a[r]&&isalpha(w[l])&&isalpha(a[r])) return false;
            while(w[l]==a[r]&&isalpha(w[l])&&isalpha(a[r])){
                r++;
                l++;
            }
            while(isdigit(a[r])){
                str+=a[r];
                r++;
            }

            //注意是否有前导零
            for(auto &x:str){
                if(x=='0'&&!tag) return false;
                if(x!='0') tag=true;
            }

            if(str!="") shuzi=stoi(str);
            else shuzi=0;

            str=""; //记录数字的字符串归位
            while(shuzi--){
                l++;
            }
        }
        if(l!=w.length()||r!=a.length()) return false; //如果没有同时遍历完，返回false;
        return true;
    }
};