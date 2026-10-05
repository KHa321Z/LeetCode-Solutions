class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0, dep = 0;

        for (int i = 0; i < s.length(); i++)
            if (s[i] == '(')
                dep++;
            else {
                dep--;
                if (s[i - 1] == '(')
                    score += (1 << dep);
            }

        return score;
    }
};