class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        
        int n = nums.size();
        long long left = 0, right = 0, cnt = 0;

        for (int i = 0; i < n / 2; i++)
            left += nums[i], right += nums[i + n / 2];

        for (int i = 0; i < n; i++) {
            if (left > right) cnt++;
            left += (nums[(n / 2 + i) % n] - nums[i]);
            right += (nums[i] - nums[(n / 2 + i) % n]);
        }

        return cnt;

    }
};