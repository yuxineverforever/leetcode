/**
 * Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
    '.' Matches any single character.
    '*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example:
 *Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".


 * A: dynamic programming. hard to explain here.
 * https://leetcode-cn.com/problems/regular-expression-matching/solution/shou-hui-tu-jie-wo-tai-nan-liao-by-hyj8/
 *
 * @param s
 * @param p
 * @return
 */
bool isMatch(string s, string p) {
  s = " " + s;
  p = " " + p;
  int m = s.size(), n = p.size();
  bool dp[m + 1][n + 1];
  memset(dp, false, (m + 1) * (n + 1));
  dp[0][0] = true;

  for (int i = 1; i <= m; i++) {

    for (int j = 1; j <= n; j++) {

      if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {

        dp[i][j] = dp[i - 1][j - 1];

      } else if (p[j - 1] == '*') {

        if (s[i - 1] != p[j - 2] && p[j - 2] != '.')
          dp[i][j] = dp[i][j - 2];
        else {
          dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j];
        }

      }
    }
  }
  return dp[m][n];
}
