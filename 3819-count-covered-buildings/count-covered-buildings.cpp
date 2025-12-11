class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        int cnt = 0;
        unordered_map<int, vector<int>> x, y;

        sort(buildings.begin(), buildings.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        for (auto& pnt : buildings)
            x[pnt[0]].push_back(pnt[1]);

        sort(buildings.begin(), buildings.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });

        for (auto& pnt : buildings)
            y[pnt[1]].push_back(pnt[0]);

        for (auto& pnt : buildings) {
            auto& X = x[pnt[0]];
            auto& Y = y[pnt[1]];
            auto r = upper_bound(X.begin(), X.end(), pnt[1]);
            auto l = lower_bound(X.begin(), X.end(), pnt[1]);
            auto d = upper_bound(Y.begin(), Y.end(), pnt[0]);
            auto u = lower_bound(Y.begin(), Y.end(), pnt[0]);

            if (r != X.end() && l != X.begin() && d != Y.end() && u != Y.begin())
                cnt++;
        }

        return cnt;
        
    }
};