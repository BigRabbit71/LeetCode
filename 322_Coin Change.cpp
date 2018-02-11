class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //0, 1, ..., amount
        vector<int> f(amount+1, 0);  
        int n = coins.size();
        
        f[0] = 0;
        for(int i=1; i<(amount+1); ++i){
            f[i] = INT_MAX;
            for(int j=0; j<n; ++j){
                if(i>=coins[j] && f[i-coins[j]]!= INT_MAX && f[i-coins[j]]+1 < f[i]) 
                    //f[i-coins[j]] = INT_MAX, 则+1后溢出为负数，必然小于INT_MAX
                    f[i] = f[i-coins[j]]+1;
            }
        }
        if(f[amount] == INT_MAX) return -1;
        else return f[amount];
    }
};