class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int l1 = str1.length(), l2 = str2.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

        for (int row = 0; row <= l1; row++)
            dp[row][0] = row;

        for (int col = 0; col <= l2; col++)
            dp[0][col] = col;

        for (int row = 1; row <= l1; row++)
            for (int col = 1; col <= l2; col++)
                if (str1[row - 1] == str2[col - 1])
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                else
                    dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + 1;

        string supseq = "";
        int row = l1, col = l2;

        while (row > 0 && col > 0)
            if (str1[row - 1] == str2[col - 1])
                supseq += str1[row - 1], 
                row--, col--;

            else if (dp[row - 1][col] < dp[row][col - 1])
                supseq += str1[row - 1], 
                row--;

            else
                supseq += str2[col - 1], 
                col--;

        while (row > 0)
            supseq += str1[row - 1], 
            row--;

        while (col > 0)
            supseq += str2[col - 1], 
            col--;

        reverse(supseq.begin(), supseq.end());
        return supseq;

    }
};