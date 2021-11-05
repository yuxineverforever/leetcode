/**
 *
 * Q: The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 * Given an integer n, return the number of distinct solutions to the n-queens puzzle.
 *
 * A: use bitmap here.
 * https://leetcode-cn.com/problems/n-queens-ii/
 *
 */
class Solution {
public:
    int totalNQueens(int n) {
        dfs(n, 0, 0, 0, 0);

        return this->res;
    }

    void dfs(int n, int row, int col, int ld, int rd) {
        if (row >= n) {
            res++;
            return;
        }
        // 将所有能放置 Q 的位置由 0 变成 1，以便进行后续的位遍历
        int bits = ~(col | ld | rd) & ((1 << n) - 1);
        while (bits > 0) {
            int pick = bits & -bits;    // comment: x & -x
            dfs(n, row + 1, col | pick, (ld | pick) << 1, (rd | pick) >> 1);
            bits &= bits - 1;           // comment: x & (x - 1)
        }
    }
private:
    int res = 0;
};

/**
 * Use DFS here.
 *
 * Three set for location.
 * - column set: for column
 * - diagonal set 1: for left diagonal. (represented by row-column)
 * - diagonal set 2: for left diagonal. (represented by row+column)
 */

class Solution {
public:
    int totalNQueens(int n) {
        unordered_set<int> columns, diagonals1, diagonals2;
        return backtrack(n, 0, columns, diagonals1, diagonals2);
    }

    int backtrack(int n, int row, unordered_set<int>& columns, unordered_set<int>& diagonals1, unordered_set<int>& diagonals2) {
        if (row == n) {
            return 1;
        } else {
            int count = 0;

            for (int i = 0; i < n; i++) {

                if (columns.find(i) != columns.end()) {
                    continue;
                }

                int diagonal1 = row - i;

                if (diagonals1.find(diagonal1) != diagonals1.end()) {
                    continue;
                }

                int diagonal2 = row + i;

                if (diagonals2.find(diagonal2) != diagonals2.end()) {
                    continue;
                }

                columns.insert(i);
                diagonals1.insert(diagonal1);
                diagonals2.insert(diagonal2);

                count += backtrack(n, row + 1, columns, diagonals1, diagonals2);

                columns.erase(i);
                diagonals1.erase(diagonal1);
                diagonals2.erase(diagonal2);

            }
            return count;
        }
    }
};