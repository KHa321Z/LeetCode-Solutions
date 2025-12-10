class Solution {
public:
    int countPermutations(vector<int>& complexity) {

        const int MOD = 1e9 + 7;
        int n = complexity.size();
        int ans = 1;

        if (*min_element(complexity.begin() + 1, complexity.end()) <= complexity[0])
            return 0;

        for (int i = 2; i < n; i++)
            ans = (long long)ans * i % MOD;

        return ans;
        
    }
};