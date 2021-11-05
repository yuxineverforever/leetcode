/**
 *  You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists.

    The depth of an integer is the number of lists that it is inside of. For example, the nested list [1,[2,2],[[3],2],1] has each integer's value set to its depth.

    Return the sum of each integer in nestedList multiplied by its depth.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/nested-list-weight-sum
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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