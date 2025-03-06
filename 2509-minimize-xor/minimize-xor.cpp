class Solution {
public:
    int minimizeXor(int num1, int num2) {

        int numOfBits = 0;
        int mask = 1;
        int result = 0;

        while (num2) {
            if (num2 % 2)
                numOfBits++;

            num2 >>= 1;
        }

        while (mask <= num1)
            mask <<= 1;

        mask >>= 1;

        while (mask && numOfBits) {
            if (mask & num1)
                result |= mask, 
                numOfBits--;
            
            mask >>= 1;
        }

        mask = 1;

        while (numOfBits) {
            if (!(mask & num1))
                result |= mask, 
                numOfBits--;

            mask <<= 1;
        }

        return result;
        
    }
};