class Solution {
public:
    bool divideArray(vector<int>& nums) {

        unordered_map<int, int> mep;

        for (int i = 0; i < nums.size(); i++)
            mep[nums[i]]++;

        for (auto num : mep)
            if (num.second % 2)
                return false;

        return true;
        
    }
};