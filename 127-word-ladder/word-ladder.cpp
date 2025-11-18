class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        queue<pair<string, int>> q;
        unordered_set<string> w(wordList.begin(), wordList.end());

        if (!w.count(endWord) || beginWord == endWord)
            return 0;

        w.erase(beginWord);
        q.push({beginWord, 1});

        while (!q.empty()) {

            auto s = q.front();
            q.pop();

            if (s.first == endWord)
                return s.second;

            for (char& ch : s.first) {
                char e = ch;

                for (char c = 'a'; c <= 'z'; c++) {
                    ch = c;

                    if (w.count(s.first))
                        q.push({s.first, s.second + 1}), 
                        w.erase(s.first);
                }

                ch = e;
            }

        }

        return 0;
        
    }
};