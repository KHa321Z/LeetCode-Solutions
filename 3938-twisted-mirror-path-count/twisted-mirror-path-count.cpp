class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        
        const int MOD = 1e9 + 7;
        int n = grid.size(), m = grid[0].size();

        vector<array<long long, 2>> f(m, {0, 0});
        f[0][0] = 1;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (i)
                    f[j][0] = (grid[i - 1][j] == 0) ? (f[j][0] + f[j][1]) % MOD : f[j][1];

                if (j)
                    f[j][1] = (grid[i][j - 1] == 0) ? (f[j - 1][0] + f[j - 1][1]) % MOD : f[j - 1][0];   
            }

        return (f[m - 1][0] + f[m - 1][1]) % MOD;

    }
};