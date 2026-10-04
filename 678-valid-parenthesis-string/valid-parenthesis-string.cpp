class Solution {
public:
    int brute(vector<vector<int>>& dp, const string& s, int pos=0, int op=0) {
        if (op < 0 || op > (int)s.length() - pos)
            return 0;

        else if (pos == s.length())
            return (op == 0);

        else if (dp[pos][op] != -1)
            return dp[pos][op];

        if (s[pos] == '*')
            return dp[pos][op] = brute(dp, s, pos + 1, op + 1) || brute(dp, s, pos + 1, op - 1) || brute(dp, s, pos + 1, op);

        return dp[pos][op] = brute(dp, s, pos + 1, (s[pos] == '(') ? op + 1 : op - 1);
    }

    bool checkValidString(string s) {
        vector<vector<int>> dp((int)s.length() + 1, vector<int>((int)s.length() + 1, -1));
        return brute(dp, s);
    }
};