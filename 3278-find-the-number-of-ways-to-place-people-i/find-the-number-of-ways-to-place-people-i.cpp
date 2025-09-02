class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        
        int n = points.size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {

                bool noPoint = true;
                auto& pointA = points[i], pointB = points[j];
                
                if (i == j || pointA[0] > pointB[0] || pointA[1] < pointB[1])
                    continue;

                for (int k = 0; k < n; k++) {
                    auto& pointC = points[k];

                    if (k != i && k != j && pointC[0] <= max(pointA[0], pointB[0]) && pointC[0] >= min(pointA[0], pointB[0]) && pointC[1] <= max(pointA[1], pointB[1]) && pointC[1] >= min(pointA[1], pointB[1])) {
                        noPoint = false;
                        break;
                    }
                }

                if (noPoint)
                    cnt++;

            }

        return cnt;

    }
};