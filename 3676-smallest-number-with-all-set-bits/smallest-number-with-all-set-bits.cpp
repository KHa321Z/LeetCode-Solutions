class Solution {
public:
    int smallestNumber(int n) {
        return (1 << (int)(floor(log2(n)) + 1)) - 1;
    }
};