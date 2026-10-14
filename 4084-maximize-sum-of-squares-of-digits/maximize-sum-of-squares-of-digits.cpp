class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        
        string ans = "";

        while (num)
            ans += '0' + ((sum > 9) ? 9 : sum), 
            sum -= ((sum > 9) ? 9 : sum), 
            num--;

        return (sum) ? "" : ans;

    }
};