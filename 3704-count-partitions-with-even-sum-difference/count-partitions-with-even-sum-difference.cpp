class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        return (s & 1) ? 0 : nums.size() - 1;
    }
};