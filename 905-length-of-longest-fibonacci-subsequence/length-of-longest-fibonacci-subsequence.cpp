class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        int count = 0;
        unordered_map<int, int> mep;
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size()));

        for (int i = 0; i < arr.size(); i++)
            mep[arr[i]] = i;

        for (int i = 0; i < arr.size(); i++)
            for (int j = i + 1; j < arr.size(); j++)
                if ((mep.find(arr[j] - arr[i]) != mep.end()) && (arr[j] - arr[i] < arr[i]))
                    count = max(count, (dp[i][j] = dp[mep[arr[j] - arr[i]]][i] + 1));

                else 
                    dp[i][j] = 2;

        return (count >= 3) ? count : 0;
        
    }
};