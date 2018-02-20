class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n+1, 0); // add a f[0]=0
        
        for(int i=1; i<=n; ++i){
            // init to a non-solution state
            f[i] = INT_MAX;
            for(int x=1; x*x<=i; ++x){
                // f[i-x*x] mustn't be non-solution, needn't to judge
                if(f[i-x*x]+1 < f[i])
                    f[i] = f[i-x*x]+1;
            }
        }
        
        return f[n];
    }
};