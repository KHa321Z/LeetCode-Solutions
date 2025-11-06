class Solution {
public:bool isMatch(string s, string p) {
        
        /*
        base case: i == len(s) && j == len(p)
        recursive case:
        isMatch(i+1, j+1) if (p[j] != * && p[j] != ? && s[i] == p[j])
        isMatch(i+1, j+1) if (p[j] == ?)
        isMatch(i+1, j) || isMatch(i+1, j+1) || isMatch(i, j+1) if (p[j] == *)
        */

        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        dp[n][m] = 1;

        bool t = m && p[m - 1] == '*';

        for (int j = m - 1; j >= 0; j--)
            if (t &= (p[j] == '*'))
                dp[n][j] = 1;

        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--) {
                if (p[j] == '*' || p[j] == '?' || s[i] == p[j])
                    dp[i][j] = dp[i + 1][j + 1];

                if (p[j] == '*')
                    dp[i][j] = dp[i][j] || dp[i][j + 1] || dp[i + 1][j];
            }

        return t || dp[0][0];

    }
};