class Solution {
public:
    string removeStars(string s) {

        string stek;

        for (int i = 0; i < s.length(); i++)
            if (s[i] != '*')
                stek += s[i];
            else
                stek.pop_back();

        return stek;
        
    }
};