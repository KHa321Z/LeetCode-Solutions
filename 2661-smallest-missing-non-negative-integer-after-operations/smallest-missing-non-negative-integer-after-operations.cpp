class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        int MEX = 0;

        for (int i = 0; i < nums.size(); i++) {
            nums[i] %= value;

            if (nums[i] < 0)
                nums[i] += value;
        }

        sort(nums.begin(), nums.end());

        if (nums[0] != 0)
            return MEX;

        for (int i = 1; i < nums.size(); i++)
            if (nums[i - 1] % value == nums[i])
                nums[i] = nums[i - 1] + value;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == MEX)
                MEX++;
            else
                return MEX;
        
        return MEX;
        
    }
};