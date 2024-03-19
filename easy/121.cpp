class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // sliding windows
        int l=0,r=1;
        int max_p=0;
        
        while(r<prices.size()){
            if(prices[l]<prices[r]){
                max_p = max(max_p,prices[r]-prices[l]);
            }else l=r;
            r++;
        }
        return max_p;
    }
};
