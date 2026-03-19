class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int cnt = 0, n = grid.size(), m = grid[0].size();
        vector<vector<int>> cx(n, vector<int>(m)), cy(n, vector<int>(m));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X') cx[i][j]++;
                else if (grid[i][j] == 'Y') cy[i][j]++;

                if (i > 0)
                    cx[i][j] += cx[i - 1][j], 
                    cy[i][j] += cy[i - 1][j];
                
                if (j > 0)
                    cx[i][j] += cx[i][j - 1], 
                    cy[i][j] += cy[i][j - 1];

                if (i > 0 && j > 0)
                    cx[i][j] -= cx[i - 1][j - 1], 
                    cy[i][j] -= cy[i - 1][j - 1];

                if (cx[i][j] != 0 && cx[i][j] == cy[i][j]) cnt++;
            }

        return cnt;

    }
};