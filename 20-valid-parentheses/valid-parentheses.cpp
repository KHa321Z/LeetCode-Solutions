class Solution {
public:
    bool isValid(string s) {

        stack<char> stek;

        for (int i = 0; i < s.length(); i++)
            if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
                stek.push(s[i]);
            else if (!stek.empty() && (abs(s[i] - stek.top()) <= 2))
                stek.pop();
            else 
                return false;

        return stek.empty();
        
    }
};