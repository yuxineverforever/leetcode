/**
 * Q: Given a string s, return the longest palindromic substring in s.
 *
 * A: I love the method called center expanding.
 * "s" is a palindromic string
 * "ss" is also a palindromic string
 */
// method 1: dynamic programming
// method 2: center expanding

// This one is center expanding

#include <iostream>
#include <string>
class Solution {
public:
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    // enumerate the center of the palindromic substring.
    string longestPalindrome(string s) {
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};