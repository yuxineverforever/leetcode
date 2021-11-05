

/**
 *
 * Q: A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.
 *
 *  A: greedy algorithm.
 *
 */

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        vector<int>toA(n);
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=costs[i][0];
            toA[i]=costs[i][1]-costs[i][0];
        }
        sort(toA.begin(),toA.end());
        for(int i=0;i<n/2;i++){
            ans+=toA[i];
        }
        return ans;
    }
};