class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_map<int, int> freqs;

    for (int i = 0; i < 9; i++) {
        
        for (int j = 0; j < 9; j++) {
            if (((board[i][j] != '.') && (++freqs[board[i][j] - 48] > 1)) || ((board[j][i] != '.') && ((++freqs[10 + board[j][i] - 48] > 1) || (++freqs[20 + (j / 3) * 10 + board[j][i] - 48] > 1)))) 
                return false;
        }

        for (int j = 1; j <= 9; j++) {

            if (i % 3 == 2)
                for (int k = 0; k < 3; k++)
                    freqs[20 + k * 10 + j] = 0;

            freqs[j] = freqs[10 + j] = 0;

        }

    }

    return true;

    }
};