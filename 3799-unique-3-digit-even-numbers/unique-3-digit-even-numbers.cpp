class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        unordered_set<int> s;

        for (int i = 0; i < digits.size(); i++)
            if (digits[i] % 2 == 0)
                for (int j = 0; j < digits.size(); j++)
                    for (int k = 0; k < digits.size(); k++)
                        if (digits[j] && i != j && i != k && j != k)
                            s.insert(digits[j] * 100 + digits[k] * 10 + digits[i]);

        return s.size();

    }
};