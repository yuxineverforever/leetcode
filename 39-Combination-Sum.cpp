#include "iostream"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void dfs(vector<int>& candidates, int begin, int len, int target, vector<int>& path, vector<vector<int>>& res){

        if(target==0){
            res.push_back(path);
            return;
        }

        for(int i=begin;i<len;i++){

            if(target-candidates[i]<0){
                break;
            }

            path.push_back(candidates[i]);

            dfs(candidates,i,len,target-candidates[i],path,res);

            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int len=candidates.size();
        if(len==0){
            return res;
        }
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        dfs(candidates,0,len,target,path,res);
        return res;
    }
};

int main(){
    Solution s;
    std::vector<int> input{2,3,6,7};
    int target = 7;

    auto res = s.combinationSum(input,target);

    return 0;
}