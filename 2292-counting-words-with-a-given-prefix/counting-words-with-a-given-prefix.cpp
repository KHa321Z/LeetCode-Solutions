class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {

        int count = 0;

        for (int i = 0; i < words.size(); i++)
            if (pref.length() <= words[i].length()) {

                bool isPrefix = true;

                for (int j = 0; j < pref.length(); j++)
                    if (pref[j] != words[i][j])
                        isPrefix = false, 
                        j = pref.length();

                if (isPrefix)
                    count++;

            }

        return count;

    }
};