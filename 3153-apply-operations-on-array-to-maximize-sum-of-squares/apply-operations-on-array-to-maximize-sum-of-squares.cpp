class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        vector<int> cnt(30);

        for (int num : nums)
            for (int i = 0; i < 30; i++)
                if (num & (1LL << i))
                    cnt[i]++;

        for (int i = 0; i < k; i++) {
            long long num = 0;

            for (int j = 29; j >= 0; j--)
                if (cnt[j] > 0)
                    num |= (1LL << j), cnt[j]--;
            
            ans = (ans + num * num) % MOD;
        }

        return (int)ans;
    }
};