class Solution {
public:
    long fact(long x) { return ((x == 0) ? 1 : x * fact(x - 1)); }

    int tupleSameProduct(vector<int>& nums) {
        
        int count = 0;
        unordered_map<long, long> mep;

        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                mep[nums[i] * nums[j]]++;

        for (auto num : mep)
            if (num.second > 1)
                count += (fact(num.second) / fact(num.second - 2)) * 4;

        return count;

    }
};