class Solution {
public:
    int match(vector<vector<int>> &dp, const string &s, const string &t, int i, int j) {
        if (i == s.length())
            return (j == t.length());
        
        else if (dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = 0;

        if (s[i] == t[j])
            dp[i][j] += match(dp, s, t, i + 1, j + 1);

        return dp[i][j] += match(dp, s, t, i + 1, j);
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, -1));

        return match(dp, s, t, 0, 0);
    }
};