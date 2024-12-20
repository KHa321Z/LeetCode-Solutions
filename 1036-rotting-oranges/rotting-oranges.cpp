class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int time = -1;
        int current = 0;
        int children = 0;
        int oranges = 0;
        queue<pair<int, int>> nodes;

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2)
                    nodes.push({ i, j }), 
                    children++;

                if (grid[i][j] == 1)
                    oranges++;
            }

        if (!oranges)
            return 0;

        while (!nodes.empty()) {

            if (current == 0)
                current = children, 
                children = 0, 
                time++;

            pair<int, int> coord = nodes.front();
            nodes.pop();
            current--;

            for (int i = -1; i <= 1; i += 2) {
                if ((coord.first + i >= 0 && coord.first + i < grid.size()) && grid[coord.first + i][coord.second] == 1)
                    nodes.push({ coord.first + i, coord.second }), 
                    grid[coord.first + i][coord.second]++, 
                    oranges--, 
                    children++;

                if ((coord.second + i >= 0 && coord.second + i < grid[coord.first].size()) && grid[coord.first][coord.second + i] == 1)
                    nodes.push({ coord.first, coord.second + i }), 
                    grid[coord.first][coord.second + i]++, 
                    oranges--, 
                    children++;
            }

        }

        if (oranges)
            return -1;

        return time;

    }
};