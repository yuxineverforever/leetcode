/**
 *Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/is-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 * A Easy One.
 * @param s
 * @param t
 * @return
 */
bool isSubsequence(char * s, char * t){
    while (*s && *t) {
        if (*s == *t) {
            s++;
        }
        t++;
    }
    if (*s == '\0') {
        return true;
    } else {
        return false;
    }
}