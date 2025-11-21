class Solution {
public:
    int countPalindromicSubsequence(string s) {

        int cnt = 0;
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < s.length(); i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
            
            last[s[i] - 'a'] = i;
        }

        for (int i = 0; i < 26; i++)
            if (first[i] != -1) {
                unordered_set<char> l;

                for (int j = first[i] + 1; j < last[i]; j++)
                    l.insert(s[j]);

                cnt += l.size();
            }

        return cnt;
        
    }
};