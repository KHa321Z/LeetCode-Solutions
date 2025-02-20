class Solution {
public:
    string recursion(unordered_set<string>& seet, string curr, int index = 0) {

        if (seet.find(curr) == seet.end())
            return curr;

        if (index == curr.size())
            return "";
        
        string temp = curr;
        temp[index] = (temp[index] == '0') ? '1' : '0';

        temp = recursion(seet, temp, index + 1);
        
        if (temp == "")
            return recursion(seet, curr, index + 1);

        return temp;

    }

    string findDifferentBinaryString(vector<string>& nums) {

        unordered_set<string> seet;

        for (int i = 0; i < nums.size(); i++)
            seet.insert(nums[i]);

        return recursion(seet, nums[0]);
        
    }
};