class Solution {
public:
    char kthCharacter(int k) {
        
        string word = "a";

        while (word.length() < k) {
            string temp = "";

            for (char ch : word)
                temp += (ch + 1);

            word += temp;
        }

        return word[k - 1];

    }
};