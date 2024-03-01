class Solution {
public:
    string maximumOddBinaryNumber(string s) {

        string ones, zeros;
        int len = s.length();
        bool oneFound = false;

        for (int i = 0; i < len; i++) 
            if (s[i] == '1' && !oneFound)
                oneFound = true;
            else if (s[i] == '1')
                ones += '1';
            else 
                zeros += '0';

        return (ones + zeros + '1');
        
    }
};