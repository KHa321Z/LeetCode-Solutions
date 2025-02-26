class Solution {
public:
    bool recursion(vector<bool>& jump, vector<int>& nums, int index = 0) {

        if (index == nums.size() - 1)
            return true;

        int jomp = nums[index];

        for (int i = 1; (i <= jomp) && (index + i < nums.size()); i++)
            if (!jump[index + i] && recursion(jump, nums, index + i))
                return true;
            else 
                jump[index + i] = true;

        return false;

    }

    bool canJump(vector<int>& nums) {

        vector<bool> jump(nums.size());

        return recursion(jump, nums);
        
    }
};