class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int start = 0;
        int end = nums.size() - 1;
        int counter = end;
        vector<int> result(end + 1);

        while (start != end + 1)
            if (-nums[start] > nums[end])
                result[counter--] = nums[start] * nums[start], start++;
            else
                result[counter--] = nums[end] * nums[end], end--;

        return result;
        
    }
};