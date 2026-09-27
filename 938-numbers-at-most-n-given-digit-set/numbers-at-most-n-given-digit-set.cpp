class Solution {
public:
    vector<long long> dp;

    long long digitdp(vector<string>& digits, const string& n, int pos=0, bool tight=true, bool leading=true) {

        if (pos == n.length())
            return !leading;

        else if (!tight && !leading && dp[n.length() - pos] != -1)
            return dp[n.length() - pos];

        int lim = 0;
        long long res = 0;

        for (auto i : digits)
            if ((!tight || i[0] <= n[pos]) && (leading || i[0] != '0'))
                res += digitdp(digits, n, pos + 1, tight && i[0] == n[pos], leading && !(i[0] - '0'));

        if (!tight)
            dp[n.length() - pos] = res;

        return res;

    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        digits.push_back("0");
        dp = vector<long long>(10, -1);
        return digitdp(digits, to_string(n));
    }
};