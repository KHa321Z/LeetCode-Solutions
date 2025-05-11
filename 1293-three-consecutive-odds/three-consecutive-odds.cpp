class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {

        for (int i = 0, o = 0; i < arr.size(); i++) {
            if (arr[i] % 2)
                o++;
            else
                o = 0;

            if (o == 3)
                return true;
        }

        return false;
        
    }
};