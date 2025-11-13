class Solution {
public:
    int maxOperations(string s) {

        int ops = 0, cnt = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1')
                cnt++;
            else {
                while (i < s.length() && s[i] == '0') 
                    i++;

                ops += cnt;
                cnt++;
            }
        }

        return ops;
        
    }
};