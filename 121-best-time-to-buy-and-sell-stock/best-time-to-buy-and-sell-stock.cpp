class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;
        int buy = 0;
        int sell = 0;

        while (sell < prices.size()) {
            profit = max(profit, prices[sell] - prices[buy]);

            if ((prices[buy] > prices[sell]) && (buy < sell))
                buy++;
            else
                sell++;
        }

        return profit;
        
    }
};