class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        
        int n = grid[0].size();
        long long val = 0;
        vector<vector<long long>> g(2, vector<long long>(n));

        if (n == 1)
            return val;

        g[0][n - 1] = grid[0][n - 1];
        g[1][0] = grid[1][0];

        for (int i = 1; i < n; i++)
            g[0][n - i - 1] = grid[0][n - i - 1] + g[0][n - i], 
            g[1][i] = grid[1][i] + g[1][i - 1];

        for (int i = 0; i < n; i++) {
            val = (i == n - 1) ? g[1][i - 1] : ((i == 0) ? g[0][i + 1] : max(g[1][i - 1], g[0][i + 1]));

            if ((i != n - 1) && (g[1][i] >= g[0][i + 1])) 
                break;
        }

        return val;

    }
};