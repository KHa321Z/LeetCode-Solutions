class Solution {
public:
    int jump(vector<int>& nums) {

        int jumps = 0, currjump = 0, maxreach = 0;

        for (int i = 0; currjump < nums.size() - 1; i++) {
            maxreach = max(maxreach, i + nums[i]);

            if (i == currjump)
                currjump = maxreach, 
                jumps++;
        }

        return jumps;            
        
    }
};