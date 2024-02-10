class Solution {
public:
    bool isPalindrome(const string &subString) {
        int strLength = subString.length();

        for (int i = 0; i < strLength / 2; i++)
            if (subString[i] != subString[strLength - i - 1])
                return false;

        return true;
    }

    int countSubstrings(string s) {

        int counter = 0;

        for (int i = 0; i < s.length(); i++)
            for (int j = i; j < s.length(); j++)
                if (isPalindrome(s.substr(i, j - i + 1)))
                    counter++;
        
        return counter;
        
    }
};