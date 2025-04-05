class Solution {
public:
    int takeXOr(vector<int>& nums, int s, int i) {
        if (i == nums.size())
            return s;

        return takeXOr(nums, s ^ nums[i], i + 1) + takeXOr(nums, s, i + 1);
    }

    int subsetXORSum(vector<int>& nums) {
        return takeXOr(nums, 0, 0);
    }
};