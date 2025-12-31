class Solution {
public:
    int superEggDrop(int k, int n) {

        // base case k = 1 minimum moves = n
        // for k > 1 min(solve(k - 1, n - 1), solve(k, n - 1))
        
        int cnt = 0;
        vector<int> dp(k + 1);

        // egg broke, so it took n steps for n floors
        for (; dp[k] < n; cnt++)
            for (int j = k; j > 0; j--)
                dp[j] += 1 + dp[j - 1];

        return cnt;

    }
};