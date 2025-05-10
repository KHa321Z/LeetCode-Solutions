class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {

        int i = 0;
        long long zeros[2] = {};
        long long sums[2] = {};

        for (int num : nums1)
            if (num)
                sums[0] += num;
            else zeros[0]++;
        
        for (int num : nums2)
            if (num)
                sums[1] += num;
            else zeros[1]++;

        if (sums[0] + zeros[0] == sums[1] + zeros[1])
            return sums[0] + zeros[0];

        else if ((sums[0] < sums[1] + zeros[1] && !zeros[0]) || (sums[1] < sums[0] + zeros[0] && !zeros[1]))
            return -1;

        i = (sums[0] > sums[1] || sums[0] + zeros[0] > sums[1] + zeros[1]) ? 0 : 1;

        return sums[i] + zeros[i];

    }
};