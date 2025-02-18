class Solution {
public:
    bool recursion(string& pattern, string& num, bool used[], int index) {

        if (index == pattern.length())
            return true;

        for (int i = 1; i < 10; i++)
            if (!used[i - 1] && ((index == -1) || ((pattern[index] == 'I') && (num[num.length() - 1] < ('0' + i))) || ((pattern[index] == 'D') && (num[num.length() - 1] > ('0' + i))))) {

                used[i - 1] = true;
                num += ('0' + i);
                
                if (recursion(pattern, num, used, index + 1))
                    return true;

                used[i - 1] = false;
                num.pop_back();

            }

        return false;

    }

    string smallestNumber(string pattern) {
        
        string num = "";
        bool used[9] = {};
        recursion(pattern, num, used, -1);

        return num;

    }
};