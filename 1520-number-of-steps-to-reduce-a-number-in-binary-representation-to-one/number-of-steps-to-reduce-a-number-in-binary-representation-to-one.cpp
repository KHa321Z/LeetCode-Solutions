class Solution {
public:
    int numSteps(string s) {
        
        int cnt = 0;
        int carry = 0;

        for (int i = s.length() - 1; i > 0; i--) {
            if (carry + s[i] - '0' == 1)
                carry = 1, 
                cnt++;

            cnt++;
        }

        return cnt + (carry);

    }
};