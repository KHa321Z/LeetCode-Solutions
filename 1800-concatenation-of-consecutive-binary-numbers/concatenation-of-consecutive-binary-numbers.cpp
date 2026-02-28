class Solution {
public:
    int concatenatedBinary(int n) {
        
        long long res = 0;

        for (int i = 1; i <= n; i++) {

            res <<= (32 - __builtin_clz(i));
            res ^= i;
            res %= (long long)(1e9 + 7);

        }

        return res;

    }
};