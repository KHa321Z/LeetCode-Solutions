class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<bitset<1024>>> dp(n, vector<bitset<1024>>(m, bitset<1024>()));

        for (int i = 0, curr = 0; i < m; i++)
            curr ^= grid[0][i], 
            dp[0][i].set(curr, 1);

        for (int i = 0, curr = 0; i < n; i++)
            curr ^= grid[i][0], 
            dp[i][0].set(curr, 1);

        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                for (int p = 0; p < 1024; p++)
                    if (dp[i - 1][j].test(p) || dp[i][j - 1].test(p))
                        dp[i][j].set(p ^ grid[i][j], 1);

        for (int i = 0; i < 1024; i++)
            if (dp[n - 1][m - 1].test(i))
                return i;

        return 0;

    }
};