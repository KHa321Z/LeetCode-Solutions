class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        
        int num = 0;
        vector<bool> ans(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            num = ((num << 1) + nums[i]) % 5;
            ans[i] = (num == 0);
        }

        return ans;

    }
};