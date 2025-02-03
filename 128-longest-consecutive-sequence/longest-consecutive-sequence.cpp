class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int length = 0;
        unordered_set<int> mep;

        for (int i = 0; i < nums.size(); i++)
            mep.insert(nums[i]);

        for (int num : mep)
            if (mep.find(num - 1) == mep.end()) {
                int len = 1;

                while (mep.find(num + 1) != mep.end())
                    len++, num++;

                length = max(len, length);
            }

        return length;
        
    }
};