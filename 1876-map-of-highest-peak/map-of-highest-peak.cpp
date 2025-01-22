class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        vector<pair<int, int>> wotah;
        queue<pair<int, int>> cells;

        for (int i = 0; i < isWater.size(); i++)
            for (int j = 0; j < isWater[i].size(); j++)
                if (isWater[i][j])
                    wotah.push_back({ i, j }), 
                    cells.push({ i, j }), 
                    isWater[i][j] = -1;

        while (!cells.empty()) {

            pair<int, int> coord = cells.front();
            cells.pop();

            for (int i = -1; i <= 1; i += 2) {
                if ((coord.first + i >= 0 && coord.first + i < isWater.size()) && isWater[coord.first + i][coord.second] == 0)
                    cells.push({ coord.first + i, coord.second }), 
                    isWater[coord.first + i][coord.second] = (isWater[coord.first][coord.second] != -1 ? isWater[coord.first][coord.second] : 0) + 1;

                if ((coord.second + i >= 0 && coord.second + i < isWater[coord.first].size()) && isWater[coord.first][coord.second + i] == 0)
                    cells.push({ coord.first, coord.second + i }), 
                    isWater[coord.first][coord.second + i] = (isWater[coord.first][coord.second] != -1 ? isWater[coord.first][coord.second] : 0) + 1;
            }

        }

        for (int i = 0; i < wotah.size(); i++)
            isWater[wotah[i].first][wotah[i].second] = 0;

        return isWater;
        
    }
};