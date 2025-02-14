class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maxLen = 0;
        int left = 0;
        unordered_map<char, int> mep;

        for (int right = 0; right < s.length(); right++) {

            if ((mep.find(s[right]) != mep.end()) && (mep[s[right]] >= left))
                left = mep[s[right]] + 1;

            maxLen = max(maxLen, right - left + 1);
            mep[s[right]] = right;

        }

        return maxLen;

    }
};