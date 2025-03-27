class Solution {
public:
    int minimumIndex(vector<int>& nums) {

        int n = nums.size();
        vector<pair<int, int>> counts(n);
        unordered_map<int, int> freqs;

        for (int i = 0; i < n; i++) 
            if (++freqs[nums[i]] > (i + 1) / 2)
                counts[i] = { nums[i], freqs[nums[i]] };

        for (int i = 0; i < n - 1; i++)
            if (counts[i].first && (freqs[counts[i].first] - counts[i].second) > (n - i - 1) / 2)
                return i;
        
        return -1;

    }
};