class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> ans(1, nums[0]);

        for (int i = 1; i < nums.size(); i++)
            if (ans[ans.size() - 1] < nums[i])
                ans.push_back(nums[i]);

            else
                *(lower_bound(ans.begin(), ans.end(), nums[i])) = nums[i];

        return ans.size();

    }
};