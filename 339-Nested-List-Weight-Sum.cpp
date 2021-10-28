/**
 *
 * A simple DFS can solve everything.
 *
 */

class Solution
{
public:
    int depthSum(vector<NestedInteger>& nestedList)
    {
        return dfs(nestedList, 1);
    }

    int dfs(vector<NestedInteger> nL, int depth)
    {
        int res = 0;
        for (auto x : nL)
        {
            if (x.isInteger() == true)
                res += x.getInteger() * depth;
            else
                res += dfs(x.getList(), depth + 1);
        }
        return res;
    }
};