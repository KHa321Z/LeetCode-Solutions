class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end()), res = 0;
        for (int i : nums) res += i - mn;
        return res;
    }
};