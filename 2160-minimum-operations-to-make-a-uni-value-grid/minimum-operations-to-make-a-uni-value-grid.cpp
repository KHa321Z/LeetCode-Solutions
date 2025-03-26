class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        int count = 0;
        int median = 0;
        vector<int> nums;

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                nums.push_back(grid[i][j]);

        sort(nums.begin(), nums.end());
        median = nums[nums.size() / 2];

        for (int i = 0; i < nums.size(); i++)
            if (abs(nums[i] - median) % x == 0)
                count += abs(nums[i] - median) / x;
            else
                return -1;

        return count;
        
    }
};