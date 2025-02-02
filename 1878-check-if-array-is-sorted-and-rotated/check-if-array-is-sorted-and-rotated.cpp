class Solution {
public:
    bool check(vector<int>& nums) {

        bool rotation = false;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > nums[(i + 1) % nums.size()])
                if (!rotation)
                    rotation = true;
                else
                    return false;

        return true;
        
    }
};