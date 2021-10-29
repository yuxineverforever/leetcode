
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