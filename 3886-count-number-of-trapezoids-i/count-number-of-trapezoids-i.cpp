class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {

        const int MOD = 1e9 + 7;
        int traps = 0;
        long long lines = 0;
        unordered_map<int, pair<int, int>> pnts;

        for (auto& pnt : points)
            pnts[pnt[1]].second += pnts[pnt[1]].first++;

        for (auto& p : pnts)
            lines += p.second.second;

        for (auto& p : pnts)
            traps = (traps + p.second.second * (lines -= p.second.second) % MOD) % MOD;

        return traps;
        
    }
};