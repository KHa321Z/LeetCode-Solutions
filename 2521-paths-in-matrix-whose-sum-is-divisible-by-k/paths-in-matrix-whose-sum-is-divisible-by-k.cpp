class Solution {
public:
    const int MOD = 1e9 + 7;

    int brute(vector<vector<vector<long long>>>& dp, vector<vector<int>>& grid, int k, int i = 0, int j = 0, int s = 0) {

        if (i >= grid.size() || j >= grid[0].size())
            return 0;
        
        s = (s + grid[i][j]) % k;

        if (dp[i][j][s] != -1)
            return dp[i][j][s];

        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return dp[i][j][s] = (s % k == 0);
        
        return dp[i][j][s] = (brute(dp, grid, k, i + 1, j, s) + brute(dp, grid, k, i, j + 1, s)) % MOD;

    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {

        auto dp = vector(grid.size(), vector(grid[0].size(), vector<long long>(k, -1)));

        return brute(dp, grid, k);

    }
};