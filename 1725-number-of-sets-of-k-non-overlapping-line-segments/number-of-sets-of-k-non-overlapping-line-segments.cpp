class Solution {
public:
    const int MOD = 1e9 + 7;

    long long pow(long long a, long long e) {
        long long res = 1;
        while (e) {
            if (e & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return res;
    }

    int numberOfSets(int n, int k) {
        
        long long num = 1, den = 1;
        
        for (int i = 1; i <= 2 * k; i++)
            num = num * (n + k - i) % MOD, 
            den = (den * i) % MOD;

        return num * pow(den, MOD - 2) % MOD;

    }
};