class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int cnt = 0;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0, j = n - 1; i < m && j >= 0; j--)
            if (grid[i][j] < 0)
                cnt += m - i;
            else
                i++, j++;

        return cnt;

    }
};