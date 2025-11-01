class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.length(), bo = 0, l = 0;
        stack<pair<char, int>> ind;

        ind.push({')', -1});

        for (int i = 0; i < n; i++)
            if (s[i] == '(' || ind.top().first == ')')
                ind.push({s[i], i});

            else {
                ind.pop();
                l = max(l, i - ind.top().second);
            }

        return l;

    }
};