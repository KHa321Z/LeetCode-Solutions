class Solution {
public:
    int brute(vector<vector<vector<int>>>& dp, const string& n, int pos=0, bool tight=true, bool leading=true, bitset<10> s=0) {

        if (pos == n.length())
            return 1;

        else if (!tight && dp[n.length() - pos][s.to_ulong()][leading] != -1)
            return dp[n.length() - pos][s.to_ulong()][leading];

        int res = 0;
        int lim = (tight) ? n[pos] - '0' : 9;

        for (int i = 0; i <= lim; i++)
            if (!s.test(i)) {
                bitset<10> ns = s;
                if (i || !leading)
                    ns.set(i);
                res += brute(dp, n, pos + 1, tight && i == lim, leading && !i, ns);
            }

        if (!tight)
            dp[n.length() - pos][s.to_ulong()][leading] = res;

        return res;

    }

    int countSpecialNumbers(int n) {
        vector<vector<vector<int>>> dp(11, vector<vector<int>>((1 << 10) + 10, vector<int>(2, -1)));
        return brute(dp, to_string(n)) - 1;
    }
};