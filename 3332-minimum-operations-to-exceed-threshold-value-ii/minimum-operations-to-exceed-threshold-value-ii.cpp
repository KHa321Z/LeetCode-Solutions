class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int count = 0;
        priority_queue<long long, vector<long long>, greater<long long>> heap;

        for (int i = 0; i < nums.size(); i++)
            heap.push(nums[i]);

        while (heap.top() < k) {
    
            long long top = heap.top();
            heap.pop();
            long long top1 = heap.top();
            heap.pop();
            heap.push(2 * min(top, top1) + max(top, top1));

            count++;
            
        }

        return count;
        
    }
};