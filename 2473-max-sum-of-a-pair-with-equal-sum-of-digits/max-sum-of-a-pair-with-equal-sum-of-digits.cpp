class Solution {
public:
    int digitSum(int num) {
        int sum = 0;

        while (num)
            sum += num % 10, 
            num /= 10;

        return sum;
    }

    int maximumSum(vector<int>& nums) {

        int sum = -1;
        unordered_map<int, int*> mep;

        for (int i = 0; i < nums.size(); i++) {
            int index = digitSum(nums[i]);

            if (!mep[index])
                mep[index] = new int(i);
            else
                sum = max(sum, nums[*mep[index]] + nums[i]), 
                mep[index] = (nums[i] > nums[*mep[index]]) ? new int(i) : mep[index];
        }

        return sum;
        
    }
};