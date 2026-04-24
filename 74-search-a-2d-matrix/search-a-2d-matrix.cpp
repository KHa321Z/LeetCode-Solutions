class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, h = m * n - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            int mx = mid / n, my = mid % n;

            if (matrix[mx][my] == target)
                return true;

            else if (matrix[mx][my] < target)
                l = mid + 1;

            else
                h = mid - 1;
        }

        return false;

    }
};