class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
	int currElement = nums[0];

	for (int i = 1; i < nums.size(); i++) {

		(currElement == nums[i]) ? count++ : count--;

		if (count <= 0)
			currElement = nums[i], count = 1;

	}

	return (count <= 0) ? -1 : currElement;
    }
};