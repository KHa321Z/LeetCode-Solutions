class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        
        int res = 0;
        unordered_map<int, int> mp;
        
        sort(nums.begin(), nums.end());

        for (int i : nums) {
            mp[i + 1] = max(mp[i + 1], mp[i] + 1);
            mp[i] = max(mp[i], mp[i - 1] + 1);
            res = max({res, mp[i], mp[i + 1]});
        }

        return res;

    }
};