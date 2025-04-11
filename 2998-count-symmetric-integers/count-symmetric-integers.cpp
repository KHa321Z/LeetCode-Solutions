class Solution {
public:
    bool isSymmetric(string num) {

        if (num.length() % 2)
            return false;
            
        int first = 0, second = 0;

        for (int i = 0; i < num.length() / 2; i++)
            first += num[i] - '0', 
            second += num[num.length() - i - 1] - '0';

        return first == second;

    }

    int countSymmetricIntegers(int low, int high) {
        
        int count = 0;

        for (; low <= high; low++)
            if (isSymmetric(to_string(low)))
                count++;

        return count;

    }
};