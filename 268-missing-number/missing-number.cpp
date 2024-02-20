class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int length = nums.size();
        int sum = length * (length + 1) / 2;
        int tempSum = 0;

        for (int i = 0; i < length; i++)
            tempSum += nums[i];

        return (sum - tempSum);
        
    }
};