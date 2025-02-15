class Solution {
public:
    bool canPartition(string num, int res) {

        if (num == "" && res == 0)
            return true;

        if (res < 0)
            return false;

        for (int i = 0; i < num.length(); i++)
            if (canPartition(num.substr(i + 1), res - stoi(num.substr(0, i + 1))))
                return true;

        return false;

    }

    int punishmentNumber(int n) {

        int sum = 0;

        for (int i = 1; i <= n; i++) 
            if (canPartition(to_string(i * i), i))
                sum += i * i;

        return sum;
        
    }
};