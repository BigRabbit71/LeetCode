class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        if(prices.size()==1) return 0;
        
        int max_profit = INT_MIN;
        int min_price = INT_MAX;
        
        min_price = prices[0];
        for(int i=1; i<prices.size(); ++i){
            if(prices[i-1]<min_price) 
                min_price = prices[i-1];
            
            if(prices[i]-min_price > max_profit)
                max_profit = prices[i]-min_price;
        }
        
        return max(max_profit, 0);
    }
};