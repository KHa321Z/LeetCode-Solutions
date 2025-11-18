class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {

        for (int i = 0; i < bits.size(); i++)
            if (bits[i] == 0)
                continue;
            else {
                if (bits.size() - i < 3)
                    return false;
                i++;
            }

        return true;
        
    }
};