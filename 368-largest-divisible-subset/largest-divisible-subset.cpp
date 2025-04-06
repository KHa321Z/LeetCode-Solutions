class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int maxi = 0;
        vector<int> res, dp(nums.size(), 1), prev(nums.size(), -1);

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++)
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1, 
                    prev[i] = j;

            if (dp[i] > dp[maxi])
                maxi = i;
        }

        for (int i = maxi; i >= 0; i = prev[i])
            res.push_back(nums[i]);

        return res;

    }
};