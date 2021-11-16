/**
    Q: Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

    A: hashmap.
**/

class Solution {
public:
    bool judgeSquareSum(int c) {

        unordered_map<int, int>mp;

        for(int i = 0;i*i<=c;i++){
            mp[i*i]=i;
        }

        for(auto it:mp){

            int first_num=it.first;
            int sec_num=c-it.first;

            if(mp.find(sec_num) != mp.end()){
                return true;
            }

        }
        return false;
    }
};