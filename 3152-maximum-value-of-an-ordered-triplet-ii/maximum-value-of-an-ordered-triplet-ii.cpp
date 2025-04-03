class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        long long res = 0, imax = 0, jmax = 0;

        for (int i = 0; i < nums.size(); i++)
            res = max(res, jmax * nums[i]), 
            jmax = max(jmax, imax - nums[i]), 
            imax = max(imax, (long long)nums[i]);

        return res;

    }
};