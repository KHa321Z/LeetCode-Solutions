class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {

        vector<string> substrings;

        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words.size(); j++) 
                if (i != j && words[i].length() <= words[j].length()) {

                    int index = 0;

                    for (int k = 0; k < words[j].length(); k++) {
                        if (index == words[i].length())
                            break;
                        else if (words[i][index] == words[j][k])
                            index++;
                        else
                            k -= index,
                            index = 0;
                    }

                    if (index == words[i].length()) {
                        substrings.push_back(words[i]);
                        break;
                    }

                }

        return substrings;
        
    }
};