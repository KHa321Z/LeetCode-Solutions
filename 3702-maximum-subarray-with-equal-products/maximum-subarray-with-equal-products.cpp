class Solution {
public:
    int maxLength(vector<int>& nums) {

        int len = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            long long g = nums[i], l = nums[i], p = 1;
            
            for (int j = i; j < n; j++) {
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);
                p *= (long long)nums[j];

                if (p > 3000)
                    break;

                if (p == l * g)
                    len = max(len, j - i + 1);
            }
        }

        return len;
        
    }
};