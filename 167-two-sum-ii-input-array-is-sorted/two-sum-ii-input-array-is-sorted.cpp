class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        for (auto it = numbers.begin(); it < numbers.end(); it++) {
            auto sec = lower_bound(it + 1, numbers.end(), target - *it);

            if (sec != numbers.end() && *sec == target - *it)
                return {(int)distance(numbers.begin(), it) + 1, (int)distance(numbers.begin(), sec) + 1};
        }

        return {-1, -1};

    }
};