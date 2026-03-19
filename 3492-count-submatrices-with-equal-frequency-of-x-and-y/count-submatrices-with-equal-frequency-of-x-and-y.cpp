class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        bool flag = false;
        int cnt = 0, n = grid.size(), m = grid[0].size();
        vector<vector<pair<int, int>>> c(n, vector<pair<int, int>>(m));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X') c[i][j].first++, c[i][j].second = 1;
                else if (grid[i][j] == 'Y') c[i][j].first--, c[i][j].second = 1;

                if (i > 0)
                    c[i][j].first += c[i - 1][j].first, 
                    c[i][j].second |= c[i - 1][j].second;
                
                if (j > 0)
                    c[i][j].first += c[i][j - 1].first, 
                    c[i][j].second |= c[i][j - 1].second;

                if (i > 0 && j > 0)
                    c[i][j].first -= c[i - 1][j - 1].first;

                if (c[i][j].second && !c[i][j].first) cnt++;
            }

        return cnt;

    }
};