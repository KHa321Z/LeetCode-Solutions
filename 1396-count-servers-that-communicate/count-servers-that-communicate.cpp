class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowServers(m), colServers(n);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j])
                    rowServers[i]++, colServers[j]++;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] && (rowServers[i] > 1 || colServers[j] > 1))
                    count++;

        return count;

    }
};