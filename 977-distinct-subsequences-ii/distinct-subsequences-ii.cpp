class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int n = s.length();
        vector<int> dp(n + 1), last(26, -1);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';
            dp[i + 1] = dp[i] * 2 % MOD;
            if (last[ch] >= 0)
                dp[i + 1] -= dp[last[ch]];
            dp[i + 1] %= MOD;
            last[ch] = i;
        }

        return (dp[n] - 1 + MOD) % MOD;
    }
};