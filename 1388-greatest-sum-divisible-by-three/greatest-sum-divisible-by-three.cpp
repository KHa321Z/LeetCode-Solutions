class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        int m11 = 10001, m12 = 10001, m21 = 10001, m22 = 10001;
        int s = 0;

        for (int n : nums) {
            s += n;

            if (n % 3 == 1) {
                if (n < m11)
                    m12 = m11, 
                    m11 = n;
                else if (n < m12)
                    m12 = n;
            } 
            else if (n % 3 == 2) {
                if (n < m21)
                    m22 = m21, 
                    m21 = n;
                else if (n < m22)
                    m22 = n;
            }
        }

        if (s % 3 == 1)
            s -= min(m11, m21 + m22);

        else if (s % 3 == 2)
            s -= min(m21, m11 + m12);
        
        return s;
        
    }
};