class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0)
            return false;

        else if (x == 0)
            return true;

        long x1 = x;
        long x2 = 0;

        while (x)
            x2 *= 10, 
            x2 += x % 10, 
            x /= 10;
        
        return (x1 == x2);

    }
};