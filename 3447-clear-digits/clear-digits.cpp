class Solution {
public:
    string clearDigits(string s) {

        string s2;

        for (int i = 0; i < s.length(); i++)
            if (s2.length() && s[i] >= '0' && s[i] <= '9')
                s2.pop_back();
            else
                s2 += s[i];

        return s2;
        
    }
};