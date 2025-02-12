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
            cout << (mep[digitSum(nums[i])] ? *mep[digitSum(nums[i])] : 0) << " ";

            if (!mep[digitSum(nums[i])])
                mep[digitSum(nums[i])] = new int(i);
            else
                sum = max(sum, nums[*mep[digitSum(nums[i])]] + nums[i]), 
                mep[digitSum(nums[i])] = (nums[i] > nums[*mep[digitSum(nums[i])]]) ? new int(i) : mep[digitSum(nums[i])];
        }

        return sum;
        
    }
};