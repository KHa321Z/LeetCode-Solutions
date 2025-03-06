class Solution {
public:
    int minimumLength(string s) {

        int len = 0;
        unordered_map<char, int> freqs;

        for (char ch : s)
            freqs[ch]++;

        for (auto ch : freqs) {
            while (ch.second > 2)
                ch.second -= 2;

            len += ch.second;
        }
        
        return len;

    }
};