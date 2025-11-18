class NumMatrix {
public:
    int m;
    int n;
    vector<vector<int>> p;

    NumMatrix(vector<vector<int>>& matrix) : p(matrix) {
        m = matrix.size();
        n = matrix[0].size();

        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
                p[i][j] += ((i + 1 < m) ? p[i + 1][j] : 0) + ((j + 1 < n) ? p[i][j + 1] : 0) - ((i + 1 < m && j + 1 < n) ? p[i + 1][j + 1] : 0);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s = p[row1][col1];

        if (row2 + 1 < m)
            s -= p[row2 + 1][col1];
        
        if (col2 + 1 < n)
            s -= p[row1][col2 + 1];

        if (row2 + 1 < m && col2 + 1 < n)
            s += p[row2 + 1][col2 + 1];

        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */