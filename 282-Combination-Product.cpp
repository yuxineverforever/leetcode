/**
 *Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/expression-add-operators
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * A little bit waste time. I will just skip this one.
 *
 */
class Solution {
    using ll = long long;
public:
    string num;
    vector<string> ret;
    int n, target;

    void dfs(string &s, int index, ll res, ll mul) {
        // 当前已达到字符串末尾，若结果正确，则加入结果数组
        // 不论正确与否，都应返回
        if (index == n) {
            if (res == target) {
                ret.emplace_back(s);
            }
            return;
        }

        // 当前表达式长度
        int m = s.size();

        if (index > 0) {
            s.push_back(0); // 占位，下面填充符号
        }

        ll val = 0;
        // 枚举截取的数字长度（取多少位），注意数字可以是单个 0 但不能有前导零
        for (int j = index; j < n && (j == index || num[index] != '0'); ++j) {
            val = val * 10 + num[j] - '0';
            s.push_back(num[j]);
            if (index == 0) {
                // 表达式开头不能添加符号
                dfs(s, j + 1, val, val);
            } else {
                // 枚举符号
                // 加法
                s[m] = '+'; dfs(s, j + 1, res + val, val);

                // 减法
                s[m] = '-'; dfs(s, j + 1, res - val, -val);

                // 乘法
                s[m] = '*'; dfs(s, j + 1, res - mul + mul * val, mul * val);
            }
        }
        s.resize(m);
    };

    vector<string> addOperators(string _num, int _target) {
        num = _num;
        n = _num.length();
        target = _target;
        string s;
        dfs(s, 0, 0, 0);
        return ret;
    }
};