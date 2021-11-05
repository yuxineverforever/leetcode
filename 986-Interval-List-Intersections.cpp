/**
 *
 * Q:You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

 *
 *
 * A: use two pointers idx1, idx2.
 *
 */

class Solution {

public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        vector<vector<int>>ans;

        int idx1=0,idx2=0;

        int n=firstList.size(),m=secondList.size();

        while(idx1<n&&idx2<m){

            int maxLeft=max(firstList[idx1][0],secondList[idx2][0]);

            int minRight=min(firstList[idx1][1],secondList[idx2][1]);

            if(maxLeft<=minRight){
                ans.push_back({maxLeft,minRight});
            }

            if(firstList[idx1][1]==minRight){
                idx1++;
            } else
                idx2++;
        }
        return ans;
    }
};