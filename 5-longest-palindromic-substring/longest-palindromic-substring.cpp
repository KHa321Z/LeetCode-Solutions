class Solution {
public:
    string longestPalindrome(string s) {

        int b = 0, e = 0;
        int n = s.length();
        vector<vector<bool>> ss(n, vector<bool>(n));

        for (int i = 0; i < n; i++)
            ss[i][i] = true;

        for (int i = 0; i < n - 1; i++)
            if (s[i] == s[i + 1])
                ss[i][i + 1] = true, 
                b = i, e = i + 1;

        for (int diff = 2; diff < n; diff++)
            for (int i = 0; i < n - diff; i++)
                if (s[i] == s[i + diff] && ss[i + 1][i + diff - 1])
                    ss[i][i + diff] = true, b = i, e = i + diff;

        return s.substr(b, e - b + 1);
        
    }
};