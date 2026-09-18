class Solution {
public:
    struct Seg {
        int l, r;
        bool operator<(const Seg& rhs) const {
            if (r == rhs.r) {
                return l > rhs.l;
            }
            return r < rhs.r;
        }
    };

    vector<string> maxNumOfSubstrings(string s) {
        vector<Seg> seg(26, (Seg){-1, -1});

        for (int i = 0; i < s.length(); ++i) {
            int charIdx = s[i] - 'a';
            seg[charIdx].r = (seg[charIdx].l == -1) ? (seg[charIdx].l = i) : i;
        }

        for (int i = 0; i < 26; ++i)
            if (seg[i].l != -1)
                for (int j = seg[i].l; j <= seg[i].r; ++j) {
                    int charIdx = s[j] - 'a';
                    if (seg[i].l <= seg[charIdx].l && seg[charIdx].r <= seg[i].r)
                        continue;

                    seg[i].l = min(seg[i].l, seg[charIdx].l);
                    seg[i].r = max(seg[i].r, seg[charIdx].r);
                    j = seg[i].l;
                }
            
        sort(seg.begin(), seg.end());
        vector<string> ans;
        int end = -1;

        for (auto& segment : seg) {
            int left = segment.l, right = segment.r;
            if (left == -1)
                continue;
            else if (end == -1 || left > end) {
                end = right;
                ans.emplace_back(s.substr(left, right - left + 1));
            }
        }
        return ans;
    }
};