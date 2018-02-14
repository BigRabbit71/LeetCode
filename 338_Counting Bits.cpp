class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> f(num+1, 0);
        
        for(int i=1; i<=num; ++i){
            f[i] = f[i>>1] + (i%2);
        }
        
        return f;
    }
};