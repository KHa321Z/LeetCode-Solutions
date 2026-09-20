class Solution {
public:
    int reverseDegree(string s) {
        
        int su = 0;

        for (int i = 0; i < s.length(); i++)
            su += (26 - (s[i] - 'a')) * (i + 1);

        return su;

    }
};