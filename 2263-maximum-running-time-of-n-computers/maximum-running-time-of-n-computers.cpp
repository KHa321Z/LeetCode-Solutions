class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {

        sort(batteries.begin(), batteries.end());
        int len = batteries.size();
        long long extra = accumulate(batteries.begin(), batteries.end() - n, 0LL);

        for (int i = 0; i < n - 1; i++) {
            if (extra / (i + 1) < batteries[len - n + i + 1] - batteries[len - n + i])
                return batteries[len - n + i] + extra / (i + 1);

            extra -= (i + 1) * (batteries[len - n + i + 1] - batteries[len - n + i]);
        }

        return batteries[len - 1] + extra / n;
        
    }
};