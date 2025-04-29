class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        int cnt = 0;
        int n = nums.size();
        int maxNum = nums[0];
        long long result = 0;

        for (int num : nums)
            maxNum = max(maxNum, num);

        for (int l = 0, r = 0; l < n; l++) {

            while (r < n && cnt != k)
                if (nums[r++] == maxNum)
                    cnt++;

            if (cnt == k)
                result += n - r + 1;

            if (nums[l] == maxNum)
                cnt--;

        }
        
        return result;
        
    }
};