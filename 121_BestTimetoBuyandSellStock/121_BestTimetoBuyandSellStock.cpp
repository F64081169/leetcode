class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 公式： max[profit(j)-price(i)] = max[profit(j)] - min[prices(i)]
        // j > i
        const int n = prices.size();
        if(n<1) return 0;

        vector<int> min_price(n); //最小成本
        vector<int> max_profit(n); //最大收益

        min_price[0] = prices[0];
        max_profit[0] = 0;
        // 1D dynamic programming
        for(int i = 1;i<n;i++){
            min_price[i] = min(prices[i],min_price[i-1]);
            max_profit[i] = max(prices[i] - min_price[i-1],max_profit[i-1]);
        }

        return max_profit[n-1];
    }
};
