class Solution {
public:
    long long countCommas(long long n) {

        long long comma = 0;
        long long commaNum = 999;

        while (commaNum < n) {
            comma += n - commaNum;
            commaNum = (commaNum * 1000) + 999;
        }

        return comma;
        
    }
};