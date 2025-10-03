class Solution {
public:

    int wrapper(string &s1, string &s2, int ind1, int ind2, vector<vector<int>>&dp) {
        if (ind1 == -1 || ind2 == -1) {
            return 0;
        }
        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }
        if (s1[ind1] == s2[ind2]) {
            return (dp[ind1][ind2] =  1 + wrapper(s1, s2, ind1 - 1, ind2 - 1, dp));
        }
        else {
            return (dp[ind1][ind2] = max(wrapper(s1, s2, ind1, ind2 - 1, dp), wrapper(s1, s2, ind1 - 1, ind2, dp)));
        }
        return 0;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n,vector<int>(m, -1));

        return wrapper(text1, text2, text1.size() - 1, text2.size() - 1, dp);
    }
};
