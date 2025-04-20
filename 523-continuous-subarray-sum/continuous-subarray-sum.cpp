class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int prefixMod = 0;
        unordered_map<int, int> mod;
        mod[0] = -1;

        for (int i = 0; i < nums.size(); i++) {

            prefixMod = (prefixMod + nums[i]) % k;

            if (mod.find(prefixMod) != mod.end()) {
                if (i - mod[prefixMod] > 1)
                    return true;
            } else
                mod[prefixMod] = i;

        }

        return false;

    }
};