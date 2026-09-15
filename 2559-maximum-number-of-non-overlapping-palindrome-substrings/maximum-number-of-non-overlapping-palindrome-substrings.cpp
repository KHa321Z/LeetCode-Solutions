class Solution {
public:
    vector<pair<int, int>> pals;

    void expand(const string& s, int l, int r, int k) {
        for (; l >= 0 && r < s.length() && s[l] == s[r]; l--, r++)
            if (r - l + 1 >= k)
                pals.emplace_back(l, r);
    }

    int maxPalindromes(string s, int k) {
        
        int n = s.length();

        for (int i = 0; i < n; i++)
            expand(s, i, i, k), expand(s, i, i + 1, k);

        sort(pals.begin(), pals.end());

        if (!pals.size())
            return 0;

        int tot = 1;
        int last = (int)pals.size() - 1;

        for (int i = (int)pals.size() - 2; i >= 0; i--)
            if (pals[i].second < pals[last].first)
                tot++, last = i;

        return tot;

    }
};