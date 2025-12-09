class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        
        const int MOD = 1e9 + 7;
        int res = 0;
        unordered_map<int, int> left, right;

        for (int n : nums)
            right[n]++;

        for (int n : nums) {
            int t = n * 2;
            right[n]--;
            res = (res + (left[t] * 1LL * right[t] % MOD)) % MOD;
            left[n]++;
        }

        return res;

    }
};