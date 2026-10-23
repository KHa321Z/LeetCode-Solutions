class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        
        int res = INT_MAX;
        vector<int> s(nums.begin(), nums.end());

        sort(s.begin(), s.end());

        for (int i = 0; i < nums.size(); i++)
            if (s[i] != nums[i])
                res &= nums[i];

        return (res == INT_MAX) ? 0 : res;

    }
};