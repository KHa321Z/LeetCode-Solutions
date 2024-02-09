class Solution {
public:
    int firstUniqChar(string s) {

        struct uniqChar {
            int index;
            int frequency = 0;
        };

        int index = s.length();
        uniqChar charsInStr[26];

        for (int i = 0; i < s.length(); i++)
            charsInStr[s[i] - 97].frequency++, charsInStr[s[i] - 97].index = i;

        for (int i = 0; i < 26; i++)
            if (charsInStr[i].frequency == 1 && charsInStr[i].index < index)
                index = charsInStr[i].index;

        return (index == s.length()) ? -1 : index;

    }
};