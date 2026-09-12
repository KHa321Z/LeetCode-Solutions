class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<tuple<int, int, int, int>> a;

        for (int i = 0; i < n; i++)
            a.emplace_back(intervals[i][0], intervals[i][1], intervals[i][2], i);

        sort(a.begin(), a.end(), [](auto&& a, auto&& b) {
            return get<1>(a) < get<1>(b);
        });

        vector<vector<long long>> dp(n + 1, vector<long long>(5));
        vector<vector<vector<int>>> ind(n + 1, vector<vector<int>>(5));

        for (int i = 0; i < n; i++) {
            auto [l, r, w, idx] = a[i];
            int k = lower_bound(a.begin(), a.begin() + i, l, [](const tuple<int, int, int, int>& t, int val) {
                return get<1>(t) < val;
            }) - a.begin();

            for (int j = 1; j < 5; j++) {
                long long s1 = dp[i][j];
                long long s2 = dp[k][j - 1] + w;

                if (s1 > s2) {
                    dp[i + 1][j] = dp[i][j];
                    ind[i + 1][j] = ind[i][j];
                    continue;
                }

                vector<int> newInd = ind[k][j - 1];
                newInd.push_back(idx);
                sort(newInd.begin(), newInd.end());

                if (s1 == s2 && ind[i][j] < newInd)
                    newInd = ind[i][j];

                dp[i + 1][j] = s2;
                ind[i + 1][j] = newInd;
            }
        }

        return ind[n][4];

    }
};