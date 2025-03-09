class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        
        int n = colors.size();
        int count = 0;
        int left = 0, right = 1;

        for (int i = 0; i < k - 1; i++)
            colors.push_back(colors[i]);

        while (right < n + k - 1) {

            if ((colors[right] != colors[right - 1]) && (right - left + 1 == k)) {
                count++;
                left++;
                right++;
            }

            else if (colors[right] == colors[right - 1]) {
                left = right;
                right++;
            }

            else 
                right++;

        }

        return count;

    }
};