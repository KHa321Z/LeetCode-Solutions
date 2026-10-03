class Solution {
public:
    int longestValidParentheses(string s) {

        int n = s.length(), best = 0;
        stack<pair<char, int>> stk;
        stk.push({')', -1});

        for (int i = 0; i < n; i++)
            if (s[i] == '(' || stk.top().first == ')')
                stk.push({s[i], i});

            else if (stk.top().first != ')')
                stk.pop(), best = max(best, i - stk.top().second);

        return best;

    }
};