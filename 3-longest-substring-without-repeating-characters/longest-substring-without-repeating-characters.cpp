class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maxLen = 0;

        for (int left = 0; left < s.length(); left++) {

            int len = 0;
            unordered_map<char, int> mep;

            for (int right = left; ((right < s.length()) && (++mep[s[right]] < 2)); right++) 
                len++;

            cout << endl;
            maxLen = max(maxLen, len);

        }

        return maxLen;

    }
};