class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        int best = 0, n = img1.size();
        vector<pair<int, int>> A, B;
        vector<vector<int>> cnt(2 * n, vector<int>(2 * n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (img1[i][j]) A.emplace_back(i, j);
                if (img2[i][j]) B.emplace_back(i, j);
            }

        for (auto& a : A)
            for (auto& b : B)
                best = max(best, ++cnt[b.first - a.first + n][b.second - a.second + n]);

        return best;

    }
};