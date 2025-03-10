class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    long long countOfSubstrings(string word, int k) {
        
        long long count = 0;
        int left = 0, right = 0;
        int consonants = 0;
        int ch[26] = {};

        int n = word.size();
        vector<int> nextConsonant(n);

        for (int i = n - 1; i >= 0; i--) {
            nextConsonant[i] = n;

            if (!isVowel(word[i]))
                n = i;
        }

        while (right < word.length()) {

            isVowel(word[right]) ? ch[word[right] - 'a']++ : consonants++;

            while (consonants > k) {
                isVowel(word[left]) ? ch[word[left] - 'a']-- : consonants--;
                left++;
            }

            while ((left < word.size()) && (ch['a' - 'a'] && ch['e' - 'a'] && ch['i' - 'a'] && ch['o' - 'a'] && ch['u' - 'a']) && (consonants == k)) {
                count += nextConsonant[right] - right;
                isVowel(word[left]) ? ch[word[left] - 'a']-- : consonants--;
                left++;
            }

            right++;

        }

        return count;

    }
};