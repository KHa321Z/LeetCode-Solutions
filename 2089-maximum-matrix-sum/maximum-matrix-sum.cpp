class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        int m = abs(matrix[0][0]);
        int o = 0, z = 0;
        long long res = 0;

        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++) {
                res += abs(matrix[i][j]);
                m = min(m, abs(matrix[i][j]));
                
                if (matrix[i][j] == 0)
                    z++;

                else if (matrix[i][j] < 0)
                    o ^= 1;
            }

        return res - ((!z && o) ? 2 * abs(m) : 0);

    }
};