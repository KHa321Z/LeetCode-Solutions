class Solution {
public:
    bool checkCuts(vector<vector<int>>& rects, int dim) {

        int gapCount = 0;

        sort(rects.begin(), rects.end(), [dim](const vector<int>& a, const vector<int>& b) {
            return a[dim] < b[dim];
        });

        int furthestEnd = rects[0][dim + 2];

        for (size_t i = 1; i < rects.size(); i++) {
            vector<int>& rect = rects[i];

            if (furthestEnd <= rect[dim])
                gapCount++;

            furthestEnd = max(furthestEnd, rect[dim + 2]);
        }

        return (gapCount >= 2);

    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return checkCuts(rectangles, 0) || checkCuts(rectangles, 1);
    }
};