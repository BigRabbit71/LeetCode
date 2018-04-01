class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        
        int n = prices.size();
        //status: 1, 2, 3, 4, 5
        //means:didn't buy, buy1, sell1, buy2, sell2
        vector<vector<int>> f(n+1, vector<int>(5+1, INT_MIN));
        
        //init
        for(int i=0; i<=n; ++i) 
        {
            f[i][1] = 0;
        }

        for(int i=1; i<=n; ++i){
            //status 1, 3, 5, didn't have stocks today(No. i-1 day)
            for(int j=1; j<=5; j+=2){
                f[i][j] = f[i-1][j];
                if(i>=2 && f[i-1][j-1]!=INT_MIN)
                    f[i][j] = max(f[i][j], f[i-1][j-1]+(prices[i-1]-prices[i-2])); 
            }
            
            //status 2, 4, have stocks today(No. i-1 day)
            for(int j=2; j<=4; j+=2){
                f[i][j] = f[i-1][j-1];
                if(i>=2 && f[i-1][j]!=INT_MIN)
                    f[i][j] = max(f[i][j], f[i-1][j]+(prices[i-1]-prices[i-2]));
                if(i>=2 && f[i-1][j-2]!=INT_MIN)
                    f[i][j] = max(f[i][j], f[i-1][j-2]+(prices[i-1]-prices[i-2]));
            }   
        }
        
        return max(max(f[n][1], f[n][3]), f[n][5]);
    }
};