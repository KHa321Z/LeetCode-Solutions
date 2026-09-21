class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<long long> res(k), dp(k);

        for (int i = 0; i < n; i++) {

            vector<long long> curr(k);
            curr[nums[i] % k]++;

            for (long long r = 0; r < k; r++)
                curr[r * nums[i] % k] += dp[r];

            dp = move(curr);

            for (int r = 0; r < k; r++)
                res[r] += dp[r];

        }

        return res;

    }
};