class Solution {
public:
    void addParanthesis(vector<string> &paras, int left, int right, int n, string p) {

        if (right == n)
            paras.push_back(p);

        if (left < n)
            addParanthesis(paras, left + 1, right, n, p + "(");

        if (right < left)
            addParanthesis(paras, left, right + 1, n, p + ")");

    }

    vector<string> generateParenthesis(int n) {

        vector<string> paranthesis;
        addParanthesis(paranthesis, 0, 0, n, "");

        return paranthesis;

    }
};