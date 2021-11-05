/***


We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:

 Q: Translate english sentence to Goat Latin sentence.


 A: one time traversal.


 **/
class Solution {
public:
  string toGoatLatin(string sentence) {
    auto words=split(sentence," ");
    for(int i=0;i<words.size();i++){
      char c=words[i][0];
      string &curWord=words[i];
      if(check(c)==false){
        curWord.erase(curWord.begin());
        curWord+=c;
      }
      curWord+="ma";
      curWord+=string(i+1,'a');
    }
    string ans;
    for(int i=0;i<words.size();i++){
      ans+=words[i];
      if(i!=words.size()-1)ans+=" ";
    }
    return ans;
  }

  vector<string>split(string&s,string c){
    vector<string>ans;
    int i=0,j;
    while((j=s.find(c,i))!=-1){
      ans.push_back(s.substr(i,j-i));
      i=j+c.size();
    }
    if(i!=s.size()){
      ans.push_back(s.substr(i));
    }
    return ans;
  }

  bool check(char c){
    if(tolower(c)=='a'||tolower(c)=='e'||tolower(c)=='i'||tolower(c)=='o'||tolower(c)=='u')return true;
    return false;
  }

};