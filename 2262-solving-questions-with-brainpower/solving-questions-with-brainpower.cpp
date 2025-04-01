class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {

        vector<long long> dp(questions.size());
        dp[dp.size() - 1] = (long long)questions[questions.size() - 1][0];

        for (int i = questions.size() - 2; i >= 0; i--) 
            dp[i] = max(dp[i + 1], questions[i][0] + (long long)((questions[i][1] + i + 1 < dp.size()) ? dp[questions[i][1] + i + 1] : 0));

        return dp[0];
        
    }
};