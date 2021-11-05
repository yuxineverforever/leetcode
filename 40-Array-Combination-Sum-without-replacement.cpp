
/**
 * Q: Given a collection of candidate numbers (candidates) and a target number (target),
 * find all unique combinations in candidates where the candidate numbers sum to target.
 * Each number in candidates may only be used once in the combination.
 * Note: The solution set must not contain duplicate combinations.
 *
 * A: dfs again
 *https://leetcode-cn.com/problems/combination-sum-ii/submissions/
 */
// author:rmokerone

#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:
  vector<int> candidates;
  vector<vector<int>> res;
  vector<int> path;
public:
  void DFS(int start, int target) {
    if (target == 0) {
      res.push_back(path);
      return;
    }

    for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
      if (i > start && candidates[i] == candidates[i - 1])
        continue;
      path.push_back(candidates[i]);
      // 元素不可重复利用，使用下一个即i+1
      DFS(i + 1, target - candidates[i]);
      path.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    this->candidates = candidates;
    DFS(0, target);
    return res;
  }
};