class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        int res = 0;
        int n = nums.size();
        unordered_map<int, int> cnt;
        unordered_set<int> unique(nums.begin(), nums.end());
        int uniqueCount = unique.size();

        for (int left = 0, right = 0; left < n; left++) {

            if (left > 0) {
                cnt[nums[left - 1]]--;

                if (cnt[nums[left - 1]] == 0)
                    cnt.erase(nums[left - 1]);
            }

            while (right < n && cnt.size() < uniqueCount) {
                cnt[nums[right]]++;
                right++;
            }

            if (cnt.size() == uniqueCount)
                res += n - right + 1;

        }

        return res;

    }
};