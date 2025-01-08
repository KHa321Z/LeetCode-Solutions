class Solution {
public:
    bool isPrefixAndSuffix(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        for (int i = 0; i < s1.length(); i++)
            if (s1[i] != s2[i])
                return false;

        for (int i = 0; i < s1.length(); i++)
            if (s1[i] != s2[s2.length() - s1.length() + i])
                return false;

        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        
        int count = 0;

        for (int i = 0; i < words.size(); i++)
            for (int j = i + 1; j < words.size(); j++)
                if (isPrefixAndSuffix(words[i], words[j]))
                    count++;

        return count;

    }
};