class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size(), sum = 0, k = 0;
        vector<int> differenceArray(n + 1);

        for (int index = 0; index < n; sum += differenceArray[index++])
            while (sum + differenceArray[index] < nums[index]) {

                if (++k > queries.size())
                    return -1;

                int l = queries[k - 1][0], r = queries[k - 1][1], val = queries[k - 1][2];

                if (r >= index)
                    differenceArray[max(l, index)] += val, 
                    differenceArray[r + 1] -= val;

            }

        return k;
        
    }
};