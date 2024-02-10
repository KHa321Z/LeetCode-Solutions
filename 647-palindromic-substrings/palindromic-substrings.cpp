class Solution {
public:
    bool isPalindrome(int &counter, string s, int start, int end) {

        if (end - start == 1)
            return ++counter;

        else if (end - start == 2)
            return (s[start] == s[end - 1]) ? ++counter : 0;

        else
            return (isPalindrome(counter, s, start + 1, end - 1) && (s[start] == s[end - 1])) ? ++counter : 0;

    }

    int countSubstrings(string s) {

        int count = 0, left = 0, right = 1;

        while (left != right) {

            isPalindrome(count, s, left, right);

            if (right == s.length())
                left++;
            else
                right++;
            
        }

        return count;

    }
};