class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        
        int n = points.size();
        int cnt = 0;

        sort(points.begin(), points.end(), [](const vector<int>& pointA, vector<int>& pointB) {
            return (pointA[0] == pointB[0]) ? (pointA[1] > pointB[1]) : (pointA[0] < pointB[0]);
        });

        for (int i = 0; i < n; i++)
            for (int j = i - 1, y = INT_MAX; j >= 0; j--)
                if (points[j][1] >= points[i][1] && points[j][1] < y)
                    y = points[j][1], cnt++;

        return cnt;

    }
};