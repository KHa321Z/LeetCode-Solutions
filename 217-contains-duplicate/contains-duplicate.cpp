class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_map<int, int> mep;

        for (int i = 0; i < nums.size(); i++)
            if (mep[nums[i]]++)
                return true;

        return false;
        
    }
};