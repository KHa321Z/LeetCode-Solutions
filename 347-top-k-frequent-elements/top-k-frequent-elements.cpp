class Solution {
public:
    struct freqElements {
    
        int element;
        int frequency;

        freqElements(int e, int f) : element(e), frequency(f) {}

        bool operator>(const freqElements &ele) {
            return ((this->frequency < ele.frequency) ? false : ((this->frequency > ele.frequency) || (this->element > ele.element)));
        }

    };

    class Compare {
        public:
            bool operator()(freqElements above, freqElements below) {
                return !((above.frequency < below.frequency) ? false : ((above.frequency > below.frequency) || (above.element > below.element)));
            }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> returnArray;
        unordered_map<int, int> mep;
        priority_queue<freqElements, vector<freqElements>, Compare> h;

        for (int i = 0; i < nums.size(); i++)
            mep[nums[i]]++;

        for (auto num : mep)
            h.push(freqElements(num.first, num.second));

        for (int i = 0; i < k; i++)
            returnArray.push_back(h.top().element), 
            h.pop();

        return returnArray;
        
    }
};