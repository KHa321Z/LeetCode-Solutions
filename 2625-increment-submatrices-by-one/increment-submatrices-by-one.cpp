class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        
        vector<vector<int>> diff(n, vector<int>(n));

        for (auto& q : queries) {
            for (int r = q[0]; r <= q[2]; r++) {
                diff[r][q[1]]++;

                if (q[3] + 1 < n)
                    diff[r][q[3] + 1]--;
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 1; j < n; j++)
                diff[i][j] += diff[i][j - 1];

        return diff;

    }
};