class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int number = 0, freq = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (freq == 0)
                number = nums[i];
            
            freq += (number == nums[i]) ? 1 : -1;
        }

        return number;

    }
};