class Solution {
public:
    bool isPalindrome(string s) {

        string s1 = "";

        for (int i = 0; i < s.length(); i++)
            if (((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= '0') && (s[i] <= '9')))
                s1 += s[i];
            else if ((s[i] >= 'A') && (s[i] <= 'Z'))
                s1 += s[i] - ('A' - 'a');

        for (int i = 0; i < s1.length() / 2; i++)
            if (s1[i] != s1[s1.length() - i - 1])
                return false;

        return true;
        
    }
};