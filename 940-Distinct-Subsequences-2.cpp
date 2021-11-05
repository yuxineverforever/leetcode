/**
 *
 * Q: Find all the valid substring of a string
 * return the result module 10^9 + 7
 *
 * Given a string s,
 * return the number of distinct non-empty subsequences of s.
 * Since the answer may be very large, return it modulo 109 + 7.
 * A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.
 * (i.e., "ace" is a subsequence of "abcde" while "aec" is not.
 *
 *
 * A:dynamic programming.
 *
 *
 */
class Solution {

public:
    int distinctSubseqII(string s) {
        int n = s.size();
        long d[n+1];
        memset(d, 0, sizeof(d));
        int mod = 1000000007;
        int last[26];
        for (int i = 0; i < 26; ++i){
            last[i] = -1;
        }

        d[0] = 1;

        for (int i = 1;i <= n; ++i){
            int curr = s[i-1] - 'a';
            d[i] = d[i-1]*2;
            if (last[curr] >= 0){
                d[i] -= d[last[curr]];
            }
            d[i] %= mod;
            last[curr] = i-1;
        }

        // 坑： 要排除本身，而且要考虑溢出的问题
        return (d[n] - 1 + mod) % mod;
    }
};