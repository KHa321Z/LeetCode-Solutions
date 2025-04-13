class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        
        int skip = n & 1;
        int base = pow(10, (n - 1) / 2);
        unordered_set<string> dict;

        for (int i = base; i < base * 10; i++) {

            string s = to_string(i);
            s += string(s.rbegin() + skip, s.rend());
            long long palindromicInt = stoll(s);

            if (palindromicInt % k == 0)
                sort(s.begin(), s.end()), 
                dict.emplace(s);

        }

        vector<long long> fact(n + 1, 1);
        long long ans = 0;

        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i;

        for (const string& s : dict) {
            vector<int> cnt(10);

            for (char c : s)
                cnt[c - '0']++;

            long long tot = (n - cnt[0]) * fact[n - 1];

            for (int x : cnt)
                tot /= fact[x];

            ans += tot;
        }

        return ans;

    }
};