class TicTacToe {
public:
    /** Initialize your data structure here. */
    int n;
    vector<vector<int>> rf;
    vector<vector<int>> cf;
    int main_diag[2];
    int sub_diag[2];

    TicTacToe(int n)
    {
        this->n = n;
        this->rf = vector<vector<int>> (2, vector<int>(n, 0));
        this->cf = vector<vector<int>> (2, vector<int>(n, 0));
        memset(main_diag, 0, sizeof(main_diag));
        memset(sub_diag, 0, sizeof(sub_diag));
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player)
    {
        int ID = player - 1;
        if (++ rf[ID][row] == n)
            return player;
        if (++ cf[ID][col] == n)
            return player;
        if (row == col)
            if (++ main_diag[ID] == n)
                return player;
        if (row == n - 1 - col)
            if (++ sub_diag[ID] == n)
                return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
