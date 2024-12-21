class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int islands = 0;
        stack<pair<int, int>> stek;

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++) {

                if (grid[i][j] == '1')
                    stek.push({ i, j }), 
                    grid[i][j]++, 
                    islands++;

                while (!stek.empty()) {

                    pair<int, int> coords = stek.top();
                    stek.pop();

                    for (int k = -1; k <= 1; k += 2) {
                        if ((coords.first + k >= 0) && (coords.first + k < grid.size()) && (grid[coords.first + k][coords.second] == '1'))
                            stek.push({ coords.first + k, coords.second }), 
                            grid[coords.first + k][coords.second]++;

                        if ((coords.second + k >= 0) && (coords.second + k < grid[coords.first].size()) && (grid[coords.first][coords.second + k] == '1'))
                            stek.push({ coords.first, coords.second + k }), 
                            grid[coords.first][coords.second + k]++;
                    }

                }

            }
        
        return islands;

    }
};