class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        
        vector<int> c(n + 1, INT_MAX);
        c[0] = 0;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 3 && i - j >= 0; j++)
                c[i] = min(c[i], c[i - j] + costs[i - 1] + j * j);

        return c[n];

    }
};