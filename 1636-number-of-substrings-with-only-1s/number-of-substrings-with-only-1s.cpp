class Solution {
public:
    int numSub(string s) {

        const int MOD = 1e9 + 7;
        int n = s.length();
        int cnt = 0;

        for (int l = 0; l < n; l++) 
            if (s[l] == '1') {

                int r = l;

                for (; r < n && s[r] == '1'; r++)
                    cnt = (cnt + r - l + 1) % MOD;

                l = r;

            }
        
        return cnt;

    }
};