class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        unordered_set<int> unique;

        for (int num : nums)
            unique.insert(num);

        int count = 0;
        int numOfUnique = unique.size();

        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> newUnique;
            for (int j = i; j < nums.size(); j++) {
                newUnique.insert(nums[j]);

                if (newUnique.size() == numOfUnique)
                    count++;
            }
        }

        return count;

    }
};