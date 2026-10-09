class Solution {
public:
    int minInsertions(string s) {
        
        int n = s.length(), ans = 0, op = 0;

        for (int i = 0; i < n; i++)
            if (s[i] == '(')
                op++;
            else {
                if (op)
                    op--;
                else
                    ans++;
                
                if (i < n - 1 && s[i + 1] == ')')
                    i++;
                else
                    ans++;
            }

        return ans + op * 2;
        
    }
};