class Solution {
public:
    string reverseParentheses(string s) {
        
        string n = "";
        stack<int> stk;

        for (int i = 0; i < s.length(); i++)
            if (s[i] == '(')
                stk.push(i);
            else if (s[i] == ')') {
                for (int j = 0; j < (i - stk.top() - 1) / 2; j++)
                    swap(s[stk.top() + j + 1], s[i - j - 1]);

                stk.pop();
            }

        for (char ch : s)
            if (ch != '(' && ch != ')')
                n += ch;

        return n;

    }
};