class Solution {
public:
    int possibleStringCount(string word) {

        int count = 1;

        for (int i = 0; i < word.length(); i++) {

            int j = i + 1;

            while (j < word.length() && word[i] == word[j])
                j++;

            if (j != i)
                count += j - i - 1, i = j - 1;

        }

        return count;
        
    }
};