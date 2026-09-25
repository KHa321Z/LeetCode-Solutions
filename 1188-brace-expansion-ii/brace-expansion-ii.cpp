class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        
        vector<char> ops;
        vector<set<string>> s;

        auto op = [&]() {
            int l = s.size() - 2, r = s.size() - 1;

            if (ops.back() == ',')
                s[l].merge(s[r]);
            else {
                set<string> temp;
                for (auto& left : s[l])
                    for (auto& right : s[r])
                        temp.insert(left + right);
                s[l] = move(temp);
            }

            s.pop_back();
            ops.pop_back();
        };

        for (int i = 0; i < expression.size(); i++)
            if (expression[i] == ',') {
                while (ops.size() && ops.back() == '*')
                    op();
                ops.push_back(',');
            }
            
            else if (expression[i] == '{') {
                if (i && (expression[i - 1] == '}' || isalpha(expression[i - 1])))
                    ops.push_back('*');
                ops.push_back('{');
            }

            else if (expression[i] == '}') {
                while (ops.size() && ops.back() != '{')
                    op();
                ops.pop_back();
            }

            else {
                if (i && (expression[i - 1] == '}' || isalpha(expression[i - 1])))
                    ops.push_back('*');
                s.push_back({ string(1, expression[i]) });
            }

        while (ops.size())
            op();

        return { s.back().begin(), s.back().end() };

    }
};