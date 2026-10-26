class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        
        int cnt = 0;
        vector<vector<bool>> v(grid.size(), vector<bool>(grid[0].size()));

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] != 0 && !v[i][j] && dfs(i, j, grid, v, k) == 0)
                    cnt++;

        return cnt;

    }

    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& v, int k) {
        int n = grid.size(), m = grid[0].size();

        if (x < 0 || x >= n || y < 0 || y >= m)
            return 0;
        
        else if (grid[x][y] == 0 || v[x][y])
            return 0;

        v[x][y] = true;
        int res = grid[x][y] % k;
        int dirx[4] = {0, 1, 0, -1};
        int diry[4] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int r = x + dirx[i], c = y + diry[i];
            res = (res + dfs(r, c, grid, v, k)) % k;
        }

        return res;
    }
};