class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        if (nums.empty()) return {-1, -1};

        auto start = lower_bound(nums.begin(), nums.end(), target), end = upper_bound(nums.begin(), nums.end(), target) - 1;

        if (start == nums.end() || *start != target)
            return {-1, -1};

        return { (int)distance(nums.begin(), start), (int)distance(nums.begin(), end) };
        
    }
};