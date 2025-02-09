class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        long long count = 0;
        unordered_map<int, int> mep;

        for (int i = 0; i < nums.size(); i++)
            count += mep[nums[i] - i]++;

        return (nums.size() * (nums.size() - 1)) / 2 - count;
        
    }
};