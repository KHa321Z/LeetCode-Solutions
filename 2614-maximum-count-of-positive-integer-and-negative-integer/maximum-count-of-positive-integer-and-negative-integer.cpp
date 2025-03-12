class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int neg = 0, pos = 0;

        for (int i = 0; i < nums.size(); i++)
            (nums[i] < 0) ? neg++ : ((nums[i] > 0) ? pos++ : 0);

        return max(neg, pos);
        
    }
};