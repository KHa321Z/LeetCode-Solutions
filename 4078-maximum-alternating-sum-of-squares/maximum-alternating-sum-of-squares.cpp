class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        int l = 0, r = nums.size() - 1;
        long long ans = 0;

        for (int i = 0; i <= r; i++)
            nums[i] = abs(nums[i]);

        sort(nums.begin(), nums.end());

        while (l < r)
            ans += 1LL * nums[r] * nums[r] - 1LL * nums[l] * nums[l], 
            l++, r--;

        return ans + ((l == r) ? nums[r] * nums[r] : 0);

    }
};