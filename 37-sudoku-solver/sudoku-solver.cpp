class Solution {
public:
    bool helper(vector<vector<char>>& board, int x, int y, char num) {

        for (int i = 0; i < 9; i++)
            if ((board[x][i] == num) || (board[i][y] == num))
                return false;

        for (int i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++)
            for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++)
                if (board[i][j] == num)
                    return false;

        return true;

    }

    bool recursion(vector<vector<char>>& board, int x = 0, int y = 0) {

        while ((x < 9) && (board[x][y] != '.')) {
            y++;
            
            if (y == 9)
                x++, y = 0;
        }

        if (x == 9)
            return true;

        for (char i = '1'; i <= '9'; i++)
            if (helper(board, x, y, i)) {
                board[x][y] = i;

                if (recursion(board, x + ((y + 1) / 9), (y + 1) % 9))
                    return true;
                    
                board[x][y] = '.';
            }

        return false;

    }

    void solveSudoku(vector<vector<char>>& board) {
        
        recursion(board);

    }
};