class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        const int MOD = 1e9 + 7;
        int count = 0;
        int oddCount = 0;
        int evenCount = 1;
        int prefixSum = 0;

        for (int i = 0; i < arr.size(); i++)
            prefixSum += arr[i], 
            count += ((prefixSum % 2) ? (oddCount++, evenCount) : (evenCount++, oddCount)), 
            count %= MOD;

        return count;
        
    }
};