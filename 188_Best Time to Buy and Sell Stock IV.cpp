class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //case 1
        if(prices.empty()) return 0;
        
        int n = prices.size();
        
        //case 2
        if(k > n/2){
            int res = 0;
            for(int i=1; i<n; ++i){
                if(prices[i] > prices[i-1])
                    res += prices[i] - prices[i-1];
            }
            return res;
        }
        
        //case 3
        //status: 1, 2, 3, 4, 5, ..., 2K+1
        //means:didn't buy, buy1, sell1, buy2, sell2, ...
        vector<vector<int>> f(n+1, vector<int>((2*k+1)+1, INT_MIN));
        
        //init
        for(int i=0; i<=n; ++i) 
        {
            f[i][1] = 0;
        }

        for(int i=1; i<=n; ++i){
            //status 1, 3, 5, didn't have stocks today(No. i-1 day)
            for(int j=1; j<=(2*k+1); j+=2){
                f[i][j] = f[i-1][j];
                if(i>=2 && f[i-1][j-1]!=INT_MIN)
                    f[i][j] = max(f[i][j], f[i-1][j-1]+(prices[i-1]-prices[i-2])); 
            }
            
            //status 2, 4, have stocks today(No. i-1 day)
            for(int j=2; j<=(2*k); j+=2){
                f[i][j] = f[i-1][j-1];
                if(i>=2 && f[i-1][j]!=INT_MIN)
                    f[i][j] = max(f[i][j], f[i-1][j]+(prices[i-1]-prices[i-2]));
                if(i>=2 && f[i-1][j-2]!=INT_MIN)
                    f[i][j] = max(f[i][j], f[i-1][j-2]+(prices[i-1]-prices[i-2]));
            }   
        }
        
        int res = 0;
        for(int i=1; i<=(2*k+1); i+=2)
            res = max(res, f[n][i]);
        return res;
    }
};