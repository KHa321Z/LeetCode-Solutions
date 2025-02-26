class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int minSum = INT_MAX, maxSum = INT_MIN;
        int sum = 0, absSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            sum += nums[i];
            minSum = min(minSum, sum);
            maxSum = max(maxSum, sum);
            absSum = max(absSum, (sum >= 0) ? max(sum, sum - minSum) : max(abs(sum), abs(sum - maxSum)));

        }

        return absSum;

    }
};