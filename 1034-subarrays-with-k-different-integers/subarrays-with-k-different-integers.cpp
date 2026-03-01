class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int cnt = 0, curr = 0;
        unordered_map<int, int> mp;
        int l = 0, r = 0;

        while (r < nums.size()) {

            if (++mp[nums[r++]] == 1)
                k--;

            if (k < 0) {
                curr = 0;
                k++;
                mp[nums[l++]]--;
            }

            if (k == 0) {
                while (mp[nums[l]] > 1)
                    mp[nums[l++]]--, curr++;

                cnt += (curr + 1);
            }

        }

        return cnt;

    }
};