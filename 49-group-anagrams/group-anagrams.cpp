class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        struct charFrequency {
            int frequency[26] = {};
            int index;
        };

        int wordsCounter = 0;
        vector <charFrequency> words;
        vector <vector <string>> anagrams;

        for (int i = 0; i < strs.size(); i++) {

            bool found = false;
            charFrequency temp;

            for (char letter: strs[i])
                temp.frequency[letter - 97]++;

            for (int j = 0; j < words.size(); j++) {

                bool flag = true;

                for (int k = 0; k < 26; k++)
                    if (temp.frequency[k] != words[j].frequency[k])
                        flag = false;

                if (flag) {
                    found = true;
                    anagrams[words[j].index].push_back(strs[i]);

                    break;
                }

            }

            if (!found) {
                temp.index = wordsCounter++;
                words.push_back(temp);
                anagrams.insert(anagrams.begin() + temp.index, {strs[i]});
            }

        }

        return anagrams;

    }
};