/**
 *
 * Q: given a string like "((())", add some '(' or ')' to make it valid.
 *
 * A: one time traversal.
 * cnt is a counter tracking how many '(' we have passed.
 * if it is a '(' then cnt++
 * if it is a ')' && cnt > 0 then cnt --
 * else ans++
 */
class Solution {
public:
  int minAddToMakeValid(string s) {
    int n=s.size();
    int cnt=0;
    int ans=0;
    for(auto&c:s){
      if(c=='('){
        cnt++;
      }else if(c==')'){
        if(cnt>0)cnt--;
        else ans++;
      }
    }
    ans+=cnt;
    return ans;
  }
};