class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        int left = 0, right = 0;
        int maxCount = 0, count = 0;
        int currNum = 0;

        while (right < nums.size())

            if ((currNum & nums[right]) == 0)
                currNum |= nums[right++], 
                count++;
            
            else
                currNum ^= nums[left++], 
                maxCount = max(maxCount, count), 
                count--;

        return max(maxCount, count);
        
    }
};