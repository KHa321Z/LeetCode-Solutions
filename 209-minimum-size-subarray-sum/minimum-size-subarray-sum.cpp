class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int m = INT_MAX, s = 0;

        for (int l = 0, r = 0; r < nums.size(); r++) {
            s += nums[r];

            for (; l <= r && s >= target; l++)
                m = min(m, r - l + 1), 
                s -= nums[l];
        }
        
        return (m == INT_MAX) ? 0 : m;
        
    }
};