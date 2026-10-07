class Solution {
public:
    bool build(const string& s, int mask, string& out) {
        out.clear();
        int bal = 0, j = 0;
        for (char c : s) {
            if (c == '(' || c == ')') {
                if ((mask >> j++) & 1)
                    continue;
                bal += (c == '(') ? 1 : -1;
                if (bal < 0) return false;
            }
            out += c;
        }
        return bal == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        int p = 0, open = 0, close = 0;

        for (char c : s)
            if (c == '(')
                p++, open++;
            else if (c == ')') {
                p++;
                (open > 0) ? open-- : close++;
            }
            
        int k = open + close;
        unordered_set<string> res;
        string cur;

        for (int mask = 0; mask < (1 << p); mask++)
            if (__builtin_popcount(mask) != k)
                continue;
            else if (build(s, mask, cur))
                res.insert(cur);

        return vector<string>(res.begin(), res.end());
    }
};