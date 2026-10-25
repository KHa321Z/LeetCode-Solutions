class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int cnt = 0;
        vector<vector<bool>> v(grid.size(), vector<bool>(grid[0].size()));

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 0 && !v[i][j] && dfs(i, j, grid, v))
                    cnt++;

        return cnt;

    }

    bool dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& v) {
        int n = grid.size(), m = grid[0].size();

        if (x < 0 || x >= n || y < 0 || y >= m)
            return false;
        
        else if (grid[x][y] == 1 || v[x][y])
            return true;

        v[x][y] = true;
        bool close = true;
        int dirx[4] = {0, 1, 0, -1};
        int diry[4] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int r = x + dirx[i], c = y + diry[i];
            if (!dfs(r, c, grid, v))
                close = false;
        }

        return close;
    }
};